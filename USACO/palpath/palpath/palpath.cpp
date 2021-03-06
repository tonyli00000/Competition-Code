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
#define INF 10000000
#define MOD 1000000007
#define MAXN 505
using namespace std;
long long dp[2][MAXN][MAXN], p[MAXN][MAXN];
int main()
{
	bool debug = 0;
	if (!debug) {
		freopen("palpath.in", "r", stdin);
		freopen("palpath.out", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string>s(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	memset(dp, 0, sizeof(dp));

	bool curr = 1, last = 0;
	int nn = n + n;
	dp[0][1][n] = 1;
	for (int i = 1; i <= n; i++) {
		swap(curr, last);
		memset(dp[last], 0, sizeof(dp[last]));
		for (int j = 1; j <= i; j++) {
			int b = n - i + 1;
			for (int k = n; k >= b; k--)
				if (dp[curr][j][k]){
					int y1 = i - j + 1, y2 = n - i + n - k + 1;
					dp[curr][j][k] %= MOD;
					if (j + 1 <= n && k - 1 >= 1 && s[j + 1][y1 - 1] == s[k - 1][y2 - 1])
						dp[last][j + 1][k - 1] += dp[curr][j][k];

					if (j + 1 <= n && y2 - 1 >= 1 && s[j + 1][y1 - 1] == s[k][y2 - 2])
						dp[last][j + 1][k] += dp[curr][j][k];

					if (y1 + 1 <= n && k - 1 >= 1 && s[j][y1] == s[k - 1][y2 - 1])
						dp[last][j][k - 1] += dp[curr][j][k];

					if (y1 + 1 <= n && y2 - 1 >= 1 && s[j][y1] == s[k][y2 - 2])
						dp[last][j][k] += dp[curr][j][k];
				}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (dp[curr][i][i] % MOD);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
	