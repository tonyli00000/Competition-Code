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
#include<cassert>
#pragma warning(disable:4996)

#define INF 100005
#define MOD 1000000007
using namespace std;
class STMax {
public:
	vector<int>num;
	vector<vector<long long>>maxx;
	int lg = 24;
	int n;
	void build() {
		int h = log2(n);
		for (int i = 0; i < n; i++) {
			maxx[i][0] = num[i];
		}
		for (int j = 1; j <= h; j++) {
			for (int k = 0; k + (1 << j) - 1 < n; k++) {
				int x = k + (1 << (j - 1));
				maxx[k][j] = max(maxx[k][j - 1], maxx[x][j - 1]);
			}
		}
	}
	STMax(vector<int>&x) :num(x) {
		n = x.size();
		maxx.resize(n + 5, vector<long long>(lg));
		build();
	}
	int query(int i, int j) {
		int h = log2(j - i + 1);
		return max(maxx[i][h], maxx[j - (1 << h) + 1][h]);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	while (cin >> n && n) {
		cin >> q;
		vector<int>x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		set<int>t; //{start, index}
		int last = -INF, p = 0;
		map<int, int>a,val;
		vector<int>ct,num;
		for (int i = 0; i < n; i++) {
			if (x[i] != last)t.insert(i), a[x[i]]=i, val[x[i]] = ct.size(),ct.push_back(1);
			else ct.back()++,a[x[i]]=i+1;
			last = x[i];
			num.push_back(ct.back());
		}
		
		STMax* maxx = new STMax(num);
		while (q--) {
			int i, j;
			cin >> i >> j;
			i--;j--;
			if (a[x[i]] > j)cout << j - i + 1 << "\n";
			else cout << max(a[x[i]] - i, maxx->query(a[x[i]], j))<<"\n";
		}
	}
	return 0;
}