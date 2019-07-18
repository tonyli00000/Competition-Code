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

using namespace std;

int main()
{
	int n,i,j;
	cin >> n;
	vector<vector<int>>v;
	vector<vector<long>>dp;
	
	dp.resize(n);
	v.resize(n);
	for (i = 1; i <= n; i++) {
		dp[i - 1].resize(i, 0);
		v[i - 1].resize(i, 0);
		for (j = 0; j < i; j++) {
			cin >> v[i - 1][j];
			dp[i - 1][j] = 0;
		}
	}
	
	for (i = 0; i <= n; i++) {
		if (i == n) {
			dp.resize(n + 1);
			dp[n].resize(1, -1);
			for (int k = 0; k < n; k++)dp[n][0] = max(dp[n][0], dp[n - 1][k]);
			continue;
		}
		for (j = 0; j <= i; j++) {
			if (!i)dp[i][j] = v[i][j];
			else {
				if (j == 0)dp[i][j] = dp[i - 1][0]+v[i][j];
				else {
					if (j == i)dp[i][j] = dp[i - 1][j - 1]+v[i][j];
					else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j])+v[i][j];
				}
			}
		}
	}
	//long ans = -1;
	//for (i = 0; i < n; i++) {
	//	if (dp[n - 1][i]>ans)ans = dp[n - 1][i];
	//}
//	cout << ans << "\n";
	
	cout << dp[n][0] << "\n";
	return 0;
}
