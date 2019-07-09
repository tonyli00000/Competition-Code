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

int i, j, k;
vector<int>num;
//vector<pair<int, int>>cluster;
int main()
{
	int n;
	cin >> n;
	int ct = 1;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
		/*if (i > 0 && x == num[i - 1])ct++;
		else {
			if (i != 0)cluster.push_back(make_pair(num[i - 1], ct));
				ct = 1;
			}
		*/
	}
	int dp[300][300];
	int ans = 0;
	for (i = 0; i < n + 3; i++) {
		for (j = 0; j < n + 3; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j<=n-i; j++) {
			int k = j + i - 1;
			if (i == 1) dp[j][k] = num[j];
			for (int l = j; l < k; l++) {
				if (dp[j][l] && dp[j][l] == dp[l + 1][k])
					dp[j][k] = max(dp[j][k], dp[j][l] + 1);
			}
			ans = max(ans, dp[j][k]);
		}
	}
	cout << ans << "\n";
    return 0;
}

