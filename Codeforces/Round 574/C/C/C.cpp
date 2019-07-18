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

#define INF 10000000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n;
	cin >> n;
	vector<int>a(n + 1),b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	vector<vector<int>>dp(n + 1, vector<int>(2,0));
	dp[1][0] = a[1];
	dp[1][1] = b[1];
	int maxx1 = a[1], maxx2 = b[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i][0], maxx2 + a[i]);
		dp[i][1] = max(dp[i][1], maxx1 + b[i]);
		maxx1 = max(maxx1, dp[i][0]);
		maxx2 = max(maxx2, dp[i][1]);
	}
	cout << max(dp[n][0], dp[n][1]) << "\n";
	return 0;
}