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
#define MOD 1000000007
#define INF 100000000000
using namespace std;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("taming.in", "r", stdin);
		freopen("taming.out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1,10000)));

	dp[0][0][1] = (x[0] != 0);
	for (int i = 1; i<n; i++){
		for (int j = 0; j <= i; j++) {
			for (int k = 1; k <= i + 1; k++) {
				if (j < i)dp[i][j][k] = dp[i - 1][j][k];
				else {
					for (int a = 0; a < i; a++) {
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][a][k - 1]);
					}
				}
				if (x[i] != i - j)dp[i][j][k]++;
			}
		}
	}

	for (int i = 1; i<=n; i++){
		int ret = 10000;
		for (int j = 0; j < n; j++) {
			ret = min(ret, dp[n - 1][j][i]);
		}
		cout << ret << '\n';
	}
	return 0;
}