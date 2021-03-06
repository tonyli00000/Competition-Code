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
long long dp[1005][10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, w, b, x, sum = 0;
	cin >> n >> w >> b >> x;
	vector<long long>tree(n+1);
	vector<long long>cost(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
		//sum += tree[i];
	}
	for (int i = 1; i <= n; i++) 
		cin >> cost[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = w;
	for (int i = 1; i <= n; i++) {
		long long p = w;
		sum += tree[i];
		for (int j = 0; j <= sum; j++) {
			for (int k = 0; k <= min(tree[i], (long long)j); k++) {
				if (dp[i - 1][j-k] == -1)continue;
				long long a = dp[i - 1][j - k] - cost[i] * k;
				if (a < 0)continue;
				dp[i][j] = max(dp[i][j], a);
			}
			if (dp[i][j] != -1)dp[i][j] += x,dp[i][j]=min(p,dp[i][j]);
			p += b;
		}
	}
	for (int i = sum; i >= 0; i--) {
		if (dp[n][i] != -1) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}