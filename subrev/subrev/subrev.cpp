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
#pragma warning(disable:4996)
using namespace std;
int dp[55][55][55][55];
int n;
vector<int> num;

void solve(int z, int k, int l, int r) {
	if (dp[z][k][l][r] >= 0) return;
	if (z >= k) {
		dp[z][k][l][r] = 0;
		return;
	}
	solve(z + 1, k, l, r);
	solve(z, k - 1, l, r);
	dp[z][k][l][r] = max(dp[z + 1][k][l][r], dp[z][k - 1][l][r]);
	if (num[z] >= l && num[z] <= r) {
		solve(z + 1, k, num[z], r);
		dp[z][k][l][r] = max(dp[z][k][l][r], dp[z + 1][k][num[z]][r] + 1);
	}
	if (num[k - 1] >= l && num[k - 1] <= r) {
		solve(z, k - 1, l, num[k - 1]);
		dp[z][k][l][r] = max(dp[z][k][l][r], dp[z][k - 1][l][num[k - 1]] + 1);
	}
	if (z < k - 1 && l <= num[k - 1] && num[k - 1] <= num[z] && num[z] <= r) {
		solve(z + 1, k - 1, num[k - 1], num[z]);
		dp[z][k][l][r] = max(dp[z][k][l][r], dp[z + 1][k - 1][num[k - 1]][num[z]] + 2);
	}
	if (z < k - 1 && l <= num[k - 1] && num[k - 1] <= r) {
		solve(z + 1, k - 1, num[k - 1], r);
		dp[z][k][l][r] = max(dp[z][k][l][r], dp[z + 1][k - 1][num[k - 1]][r] + 1);
	}
	if (z < k - 1 && l <= num[z] && num[z] <= r) {
		solve(z + 1, k - 1, l, num[z]);
		dp[z][k][l][r] = max(dp[z][k][l][r], dp[z + 1][k - 1][l][num[z]] + 1);
	}
}

int main() {
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	for (int i = 0; i < 55; i++){
		for (int j = 0; j < 55; j++){
			for (int k = 0; k < 55; k++){
				for (int l = 0; l < 55; l++){
					dp[i][j][k][l] = -100;
				}
			}
		}
	}
	cin >> n;
	num.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		num[i]--;
	}

	solve(0, n, 0, 49);
	cout << dp[0][n][0][49] << "\n";
	return 0;
}

