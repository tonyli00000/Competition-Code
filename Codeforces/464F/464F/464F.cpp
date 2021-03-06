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
#define INF 100000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>x(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i].first >> x[i].second;
	}
	vector<vector<int>>dp(m+5, vector<int>(2 * n + 5, INF));
	//dp[i][j]=Minimum number of flips to get j seconds on the top side in the first i intervals
	dp[0][0] = 0;
	vector<int>pos(n + 5, 0);
	for (int i = 1; i <= m; i++){
		int h = 1, t = 0;
		int l = x[i - 1].first, r = x[i - 1].second;
		for (int j = 0; j <= n; j++) dp[i][j] = dp[i - 1][j];
		for (int j = 0; j <= r; j++){ //Flipped twice
			if (j <= n){
				while (h <= t && dp[i - 1][j] <= dp[i - 1][pos[t]]) {
					t--;
				}
				t++;
				pos[t] = j;
			}
			while (h <= t && pos[h] < j - (r - l)) {
				h++;
			}
			if (h <= t) dp[i][j] = min(dp[i][j], dp[i - 1][pos[h]] + 2);
		}
		h = 1, t = 0;
		for (int j = r; j >= 0; j--){ //Flipped once
			if (r - j <= n){
				while (h <= t && dp[i - 1][r - j] <= dp[i - 1][pos[t]]) {
					t--;
				}
				t++;
				pos[t] = r - j;
			}
			while (h <= t && pos[h] < l - j) {
				h++;
			}
			if (h <= t) dp[i][j] = min(dp[i][j], dp[i - 1][pos[h]] + 1);
		}
	}
	if (dp[m][n] == INF)cout << "Hungry\n";
	else {
		cout << "Full\n";
		cout << dp[m][n] << "\n";
	}
	//vector<int>coins(k);
	//for (int i = 0; i < k; i++) {
	//	int x, y;
	//	cin >> x >> y;
	//	coins[i] = y - x;
	//}
	//vector<int> dp(2*n+1, INF);
	//dp[0] = 0;
	//for (int i = 1; i <= coins.size(); i++) {
	//	for (int j = 2*n; j >= 0; j--) {
	//		if (dp[j]!=INF) {
	//			dp[j + coins[i - 1]] = min(dp[j + coins[i - 1]],dp[j]+1);
	//		}
	//	}
	//}
	//if (dp[2 * n] == INF)cout << "Hungry\n";
	//else {
	//	cout << "Full\n";
	//	cout << dp[2 * n] << "\n";
	//}
	return 0;
}