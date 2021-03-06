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

using namespace std;

pair<long long,long long> count(int i, int j, vector<pair<long long, long long>>&ct) {
	return { ct[j].first - ct[i].first,ct[j].second - ct[i].second };
}
//long long dp[500][500];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<long long, long long>>ct(n+1, { 0,0 }); //{red,blue}
	ct[0] = { 0,0 };
	vector<vector<long long>>dp(k+1, vector<long long>(n+1, 600000000000000));
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		ct[i] = ct[i - 1];
		if (s[i-1] == 'r')ct[i].first += x;
		else ct[i].second += x;
	}
	//vector<vector<long long>>dp(k + 1, vector<long long>(n + 1, 0)); //dp[i][j]=max sum with i cuts where the last cut is at j
	dp[0][0] = 0;
	for (int i = 1; i < k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int a = j-1; a >= 0; a--) {
				long long r = count(a, j, ct).first*count(a, j, ct).second;
				dp[i][j] = min(dp[i][j], dp[i - 1][a] + r);
			}
		}
	}
	long long ans = dp[k-1][1]+ count(1, n, ct).first*count(1, n, ct).second;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dp[k - 1][i] + count(i, n, ct).first*count(i, n, ct).second);
	}
	if (k == 1)cout << count(0, n, ct).first*count(0, n, ct).second;
	else cout << ans << "\n";
	//cout << dp[k-1][n-1] << "\n";
	return 0;
}