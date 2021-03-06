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
map<int, int>p;
int sq;
bool comp(pair<int, int>x, pair<int, int>y) {
	if (x.second / sq == y.second / sq)return x.first < y.first;
	return x.second / sq < y.second / sq;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	sq = sqrt(n);
	vector<long long>a(n);
	vector<pair<int, int>>query(m);
	map<pair<int, int>,int>ans;
	vector<pair<int, int>>s(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		query[i] = { x,y };
		s[i] = query[i];
	}
	sort(query.begin(), query.end(), comp);
	unordered_map<long long, int>ct;
	int curr = 0;
	for (int i = query[0].first; i <= query[0].second; i++) {
		ct[a[i]]++;
		if (ct[a[i]] == a[i])curr++;
		if (ct[a[i]] == a[i] + 1)curr--;
	}
	ans[query[0]] = curr;
	for (int i = 1; i < m; i++) {
		int x1 = query[i - 1].first, y1 = query[i - 1].second, x2 = query[i].first, y2 = query[i].second;
		if (x2 < x1) {
			for (int j = x2; j < x1; j++) {
				ct[a[j]]++;
				if (ct[a[j]] == a[j])curr++;
				if (ct[a[j]] == a[j] + 1)curr--;
			}
		}
		if (y2 > y1) {
			for (int j = y1+1; j <= y2;j++) {
				ct[a[j]]++;
				if (ct[a[j]] == a[j])curr++;
				if (ct[a[j]] == a[j] + 1)curr--;
			}
		}
		if (x2 > x1) {
			for (int j = x1; j < x2; j++) {
				ct[a[j]]--;
				if (ct[a[j]] == a[j])curr++;
				if (ct[a[j]] == a[j]-1)curr--;
			}
		}
		if (y2 < y1) {
			for (int j = y2+1; j <= y1; j++) {
				ct[a[j]]--;
				if (ct[a[j]] == a[j])curr++;
				if (ct[a[j]] == a[j] - 1)curr--;
			}
		}
		ans[query[i]] = curr;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[s[i]] << "\n";
	}
	return 0;
}