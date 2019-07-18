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

int dp[80][262200];

int main() {
	freopen("262144.in", "r", stdin);
	freopen("262144.out", "w", stdout);
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int ans = 0;
	for (int i = 0; i <= 75; i++) {
		for (int j = 0; j < n; j++) {
			if (num[j] == i) {
				dp[i][j] = j + 1;
				ans = max(ans, i);
			}
			else {
				if (i == 0 || dp[i - 1][j] == -1 || dp[i - 1][dp[i - 1][j]] == -1) {
					dp[i][j] = -1;
				}
				else {
					dp[i][j] = dp[i - 1][dp[i - 1][j]];
					ans = max(ans, i);
				}
			}
		}
		dp[i][n] = -1;
	}
	cout << ans << "\n";

	return 0;
}

