/*
ID:tonyli21
PROG:theme
LANG:C++11
*/
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

int i, j, n, ans;
int main()
{
	freopen("theme.in", "r", stdin);
	freopen("theme.out", "w", stdout);
	cin >> n;
	vector<int>a(n + 2);
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			if (a[i] - a[i - 1] == a[j] - a[j - 1])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			ans = max(dp[i][j], ans);
		}
	}
	if (ans<4) ans = -1;
	cout << ans + 1 << "\n";

	return 0;
}