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
const long long MOD = 1e9 + 7;
using namespace std;

long long solve(string s, string tt) {
	int x = tt.length(), y = s.length();
	vector<vector<long long>>dp(x + 5, vector<long long>(y + 5, 0));
	for (int i = 0; i <= x; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (tt[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD;
			else dp[i][j] = dp[i - 1][j] % MOD;
			dp[i][j] %= MOD;
		}
	}
	return dp[x][y];
}
int main()
{
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	string s, t,tt;
	cin >> s >> t;
	tt = "";
	int ct = 0;
	if (n > 100) {
		while (tt.length() < s.length() * 2) {
			tt += s;
			ct++;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			tt += t;
		}
	}

	long long ans=solve(s, tt);
	if (n > 100) {
		long long ret = ans;
		for (int i = 0; i < n / ct; i++) {
			ret *= (ans%MOD);
			ret %= MOD;
		}
		tt = "";
		for (int i = 0; i < n%ct; i++) {
			tt += t;
		}
		ans=solve(s, tt);
		ret *= ans;
		cout << ret << "\n";
	}
	else cout << ans << "\n";
	return 0;
}