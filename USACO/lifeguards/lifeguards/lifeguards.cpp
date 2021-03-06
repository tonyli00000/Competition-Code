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
int n;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("lifeguards.in", "r", stdin);
		freopen("lifeguards.out", "w", stdout);
	}
	long long n, p;
	cin >> n >> p;
	vector<pair<long long,long long>>time(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> time[i].first >> time[i].second;
	}
	sort(time.begin(), time.end());
	vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(p+1, vector<long long>(2, 0)));
	long long i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= p && j<=i; j++) {
			dp[i][j][0] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]);
			for (k = j; k > 0; k--) {
				if (time[k].second >= time[i].first)break;
			}
			for (long long q = j; q >= k; q--) {
				dp[i][j][1] = max(dp[k][q][1], dp[k][q][0]);
			}
		}
	}
	cout << max(dp[n][p][0], dp[n][p][1]) << "\n";
	return 0;
}