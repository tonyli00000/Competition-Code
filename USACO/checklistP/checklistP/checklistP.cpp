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

#define INF 100000000000
#define MOD 1000000007
using namespace std;

int getdist(pair<int, int>x, pair<int, int>y) {
	int xx = x.first - y.first, yy = y.second - x.second;
	return xx * xx + yy * yy;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("checklist.in", "r", stdin);
		freopen("checklist.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>h(n), g(m);
	for (int i = 0; i < n; i++) {
		cin >> h[i].first >> h[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> g[i].first >> g[i].second;
	}
	long long dp[1005][1005][2];
	memset(dp, INF, sizeof(dp));
	dp[1][0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				if (j == 1)dp[i][j][1] = dp[i][j - 1][0] + getdist(h[i - 1], g[0]);
				else dp[i][j][1] = min(dp[i][j - 1][1] + getdist(g[j - 2], g[j - 1]),dp[i][j][1]);
				continue;
			}
			if (j == 1)dp[i][j][1] = dp[i][j - 1][0] + getdist(h[i - 1], g[0]);
			else {
				long long a = getdist(h[i - 2], h[i - 1]);
				long long b=getdist()
				dp[i][j][0]=min()
			}
		}
	}
	return 0;
}