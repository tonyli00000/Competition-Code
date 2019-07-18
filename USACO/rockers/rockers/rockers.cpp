/*
ID:tonyli21
PROG:rockers
LANG:C++11
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

#define maxn 25
int dp[maxn][maxn];
int main() {
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	int n, t, m;
	cin >> n >> t >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		for (int j = m; j >= 1; --j) {
			for (int k = 0; k <= t; ++k) {
				if (k < x) {
					if (t >= x && j < m) {
						dp[j + 1][t - x] = max(dp[j + 1][t - x], dp[j][k] + 1);
					}
				}
				else {
					dp[j][k - x] = max(dp[j][k - x], dp[j][k] + 1);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < t; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}