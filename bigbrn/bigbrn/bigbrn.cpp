/*
ID: tonyli21
TASK: bigbrn
LANG: C++
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

#define MAXN 1005

int dp[MAXN][MAXN];

int main(){
	freopen("bigbrn.in", "r", stdin);
	freopen("bigbrn.out", "w", stdout);
	int i, j, n, t, ans = 1;
	cin >> n >> t;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			dp[i][j] = -1;

	for (i = 0; i<t; i++){
		int a, b;
		cin >> a >> b;
		dp[a][b] = 0;
	}

	for (i = 1; i <= n; i++){
		if (dp[i][n] != 0)dp[i][n] = 1;
		if (dp[n][i] != 0)dp[n][i] = 1;
	}

	for (i = n - 1; i >= 1; i--){
		for (j = n - 1; j >= 1; j--){
			if (dp[i][j] != 0){
				dp[i][j] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}