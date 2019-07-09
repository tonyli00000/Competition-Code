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

long dp[100005][22][3],i,j,k;
int game[100005];
int main()
{
	long n;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'H')game[i] = 0 ;
		else if (c == 'P')game[i] = 1;
		else game[i] = 2;
	}
	for (i = 0; i < n+2; i++) {
		for (j = 0; j <= k; j++) {
			for (int l = 0; l < 3; l++) {
				dp[i][j][l] = 0;
			}
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[0][0][2] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			for (int l = 0; l < 3; l++) {
				bool win = false;
				int x = game[i];
				if (l == 0 && x == 2)win = true;
				if (l == 1 && x == 0)win = true;
				if (l == 2 && x == 1)win = true;
				if (win) {
					dp[i][j][l] = max(dp[i - 1][j][l] + 1, dp[i][j][l]);
					if (j > 0) {
						for (int temp = 0; temp < 3; temp++) {
							if (temp != l)dp[i][j][l] = max(dp[i - 1][j - 1][temp] + 1, dp[i][j][l]);
						}
					}
				}
				else {
					dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j][l]);
					if (j > 0) {
						for (int temp = 0; temp < 3; temp++) {
							if (temp != l)dp[i][j][l] = max(dp[i - 1][j - 1][temp], dp[i][j][l]);
						}
					}
				}
			}
		}
	}
	long ans = -1;
	for (i = 0; i <= k; i++) {
		for (j = 0; j < 3; j++) {
			ans = max(ans, dp[n][i][j]);
		}
	}
	cout << ans << "\n";
    return 0;
}

