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
#define MOD 1000000009
using namespace std;

long long dp[1005][1005][13];
int main(){
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	int n, m, K;
	cin >> n >> m >> K;
	vector<long long>fj(n+1), fp(m+1);
	for (int i = 1; i <= n; i++){
		cin >> fj[i];
	}
	for (int i = 1; i <= m; i++){
		cin >> fp[i];
	}
	sort(fj.begin(), fj.end());
	sort(fp.begin(), fp.end());

	for (int i = 1; i <= max(n,m); i++){
		dp[i][0][0] = 1;
		dp[0][i][0] = 1;
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j][0] = 1;
			for (int k = 1; k <= K && k<=min(i,j); k++){
				dp[i][j][k] += dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
				while (dp[i][j][k] < 0) dp[i][j][k] += (MOD);
				dp[i][j][k] %= MOD;
				if (fj[i] > fp[j]){
					dp[i][j][k] += dp[i - 1][j - 1][k - 1];
					dp[i][j][k] %= MOD;
				}
			}
		}
	}
	cout << dp[n][m][K] << "\n";
	return 0;
}