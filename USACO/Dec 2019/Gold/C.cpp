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
#pragma warning(disable:4996)

#define INF 100000000
#define MOD 1000000007
using namespace std;

#define ALL(a) a.begin(),a.end()

int main()
{
//#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("cowmbat.in", "r", stdin);
		freopen("cowmbat.out", "w", stdout);
	}

	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector<vector<int>>cost(m, vector<int>(m, INF));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cost[i][j];
		}
	}

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (cost[i][k] + cost[k][j] < cost[i][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}
	vector<vector<int>>pp(m, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int curr = 0;
		for (int j = 0; j < k; j++) {
			curr += cost[s[j] - 'a'][i];
		}
		pp[i][0] = curr;
		for (int j = 1; j <= n - k; j++) {
			curr -= cost[s[j - 1] - 'a'][i];
			curr += cost[s[j + k - 1]-'a'][i];
			pp[i][j] = curr;
		}
	}

	vector<vector<int>>dp(n, vector<int>(m, INF));
	for (int i = 0; i < m; i++) {
		dp[k - 1][i] = pp[i][0];
	}
	for (int i = k; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[s[i]-'a'][j]);
			if (i + k - 1 < n) {
				for (int a = 0; a < m; a++) {
					dp[i + k - 1][a] = min(dp[i + k - 1][a], dp[i - 1][j] + pp[a][i]);
				}
			}
		}
	}

	int ret = INF;
	for (int i = 0; i < m; i++) {
		ret = min(ret, dp[n-1][i]);	
	}
	cout << ret << "\n";
	return 0;
}