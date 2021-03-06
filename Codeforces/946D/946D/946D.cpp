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
using namespace std;
vector<vector<bool>>t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, kk;
	cin >> n >> m >> kk;
	t.resize(505, vector<bool>(505+2));
	vector<vector<int>>sum(505, vector<int>(505, 0));
	vector<vector<int>>p(505, vector<int>(505, 0));
	vector<int>x(n + 2);
	int minn = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			t[i][j] = (c - '0');
			sum[i][j] = sum[i][j - 1] + t[i][j];
		}

		sum[i][0] = 0;
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i][j - 1] + (t[i][j]);
		x[i] = sum[i][m];

		int l=1, r=0;
		int summ = 0;
		for (int j = 1; j <= m; j++) {
			if (t[i][j]) {
				l = j;
				break;
			}
		}
		for (int j = m; j >= 1; j--) {
			if (t[i][j]) {
				r = j;
				summ = r - l + 1;
				break;
			}
		}
		minn += summ;
		for (int j = l; j <= r; j++) {
			for (int k = j; k <= r; k++) {
				p[i][x[i] - sum[i][k] + sum[i][j - 1]] = max(p[i][x[i] - sum[i][k] + sum[i][j - 1]], summ - (k - j + 1));
			}
		}
		p[i][x[i]] = summ;
	}
	vector<vector<int>>dp(505, vector<int>(505, 0));
	int sub = 0;
	for (int i = 1; i <= x[1]; i++) dp[1][i] = p[1][i];
	int a = x[1];
	for (int i = 2; i <= n; i++) {
		a += x[i];
		for (int j = 0; j <= kk; j++){
			for (int k = 0; k + j <= kk; k++) {
				dp[i][k + j] = max(dp[i][j + k], dp[i - 1][j] + p[i][k]);
			}
	}
	}

	if (a <= kk)cout << 0 << "\n";
	else cout << minn - dp[n][kk] << "\n";
	return 0;
}