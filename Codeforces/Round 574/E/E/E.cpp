#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

using namespace std;
const int INF = (1e9) + 5;
class segTree {
public:
	vector<int>t;
	int n;
	segTree(int n) {
		t.resize(n * 2 + 2, INF);
		this->n = n;
	}
	void build() {  // build the tree
		for (int i = n - 1; i > 0; --i) t[i] = min(t[i << 1], t[i << 1 | 1]);
	}

	void update(int p, int value) {  // set value at position p
		for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
	}

	int query(int l, int r) {  // sum on interval [l, r)
		int ret = INF;
		r++;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, t[l++]);
			if (r & 1) ret = min(ret, t[--r]);
		}
		return ret;
	}

};

//vector<vector<int>>height(3000, vector<int>(3000));
long long sum = 0;
int n, m, a, b;
long long g, x, y, z;
int i, j, k;
priority_queue<pair<int, int>>q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//#define int long long
	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;
	vector<vector<int>>height(n, vector<int>(m));
	vector<segTree*>T(n);
	for (i = 0; i < n; i++) {
		T[i] = new segTree(m);
		for (j = 0; j < m; j++) {
			height[i][j] = g;
			g = (g * x + y) % z;
			T[i]->t[j + m] = height[i][j];
		}
		T[i]->build();
		//T[i] = new STMax(height[i]);
		height[i].clear();
	}

	for (j = 0; j < m - b + 1; j++) {
		while (!q.empty())q.pop();
		for (i = 0; i < a; i++) {
			int p = T[i]->query(j, j + b - 1);
			q.push({ -p,i });
		}
		sum += -q.top().first;
		for (int i = 1; i < n - a + 1; i++) {
			q.push({ -T[i + a - 1]->query(j, j + b - 1),i + a - 1 });
			while (true) {
				if (i <= q.top().second && q.top().second <= i + a - 1)break;
				q.pop();
			}
			sum += -q.top().first;
		}
	}
	cout << sum << "\n";
	return 0;
}