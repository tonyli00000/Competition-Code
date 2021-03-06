#include <iostream>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define MAXN 2000001
using namespace std;
long long a[MAXN];
long long ans[MAXN];
long long ct[MAXN];
int sq;
long long n, m;
int i, j;
bool comp(pair<pair<int, int>,int>x, pair<pair<int, int>, int>y) {
	if (x.first.second / sq == y.first.second / sq)return x.first.first < y.first.first;
	return x.first.second / sq < y.first.second / sq;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	sq = sqrt(n);
	vector<pair<pair<int, int>,int>>query(m);
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		query[i] = { {x,y},i };
	}
	sort(query.begin(), query.end(), comp);
	long long curr = 0,s;
	int t;
	for (i = query[0].first.first; i <= query[0].first.second; i++) {
		ct[a[i]]++;
		t = ct[a[i]];
		curr += a[i]*(t*2-1);
	}
	ans[query[0].second] = curr;
	for (i = 1; i < m; i++) {
		int x1 = query[i - 1].first.first, y1 = query[i - 1].first.second, x2 = query[i].first.first, y2 = query[i].first.second;
		if (x2 < x1) {
			for (j = x2; j < x1; j++) {
				ct[a[j]]++;
				t = ct[a[j]];
				curr += a[j] * (t * 2 - 1);
			}
		}
		if (y2 > y1) {
			for (j = y1 + 1; j <= y2; j++) {
				ct[a[j]]++;
				t = ct[a[j]];
				curr += a[j] * (t * 2 - 1);
			}
		}
		if (x2 > x1) {
			for (j = x1; j < x2; j++) {
				t = ct[a[j]];
				curr -= a[j] * (t * 2 - 1);
				ct[a[j]]--;
			}
		}
		if (y2 < y1) {
			for (j = y2 + 1; j <= y1; j++) {
				t = ct[a[j]];
				curr -= a[j] * (t * 2 - 1);
				ct[a[j]]--;
			}
		}
		ans[query[i].second] = curr;
	}
	for (i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}