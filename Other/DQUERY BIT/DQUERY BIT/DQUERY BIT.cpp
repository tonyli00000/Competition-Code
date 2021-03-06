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
#define INF 10000000
#define MOD 1000000007
using namespace std;
class segTree {
public:
	vector<int>t;
	int n;
	segTree(int n) {
		t.resize(n * 4 + 5, 0);
		this->n = n;
	}
	void build() {  
		for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
	}
	void update(int p, int value) {
		for (t[p += n] += value; p > 1; p >>= 1) t[p >> 1] = t[p]+t[p ^ 1];
	}
	int query(int l, int r) { 
		int ret = 0;
		r++;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret += t[l++];
			if (r & 1) ret += t[--r];
		}
		return ret;
	}
};
struct query {
	int l, r, id;
};
bool comp(query x, query y) {
	return x.r < y.r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int>p;
	vector<int>a(n+1), b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (p.find(a[i]) == p.end())b[i] = 0;
		else b[i] = p[a[i]];
		p[a[i]] = i;
	}
	int q;
	cin >> q;
	vector<query>query(q);
	for(int i=0;i<q;i++){
		int x, y;
		cin >> x >> y;
		query[i] = { x,y,i };
	}
	sort(query.begin(), query.end(), comp);
	vector<int>ans(q);
	int curr = 0;
	segTree* T = new segTree(n + 1);
	for (int i = 0; i < q; i++) {
		int l = query[i].l, r = query[i].r;
		while (curr < r)T->update(b[++curr], 1);
		ans[query[i].id] = r - l + 1 - T->query(l, r);
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}