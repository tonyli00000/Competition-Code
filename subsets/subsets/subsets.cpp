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
int main()
{
	int n,sum=0;
	cin >> n;

	for (k = 1; k <= n; k++)sum += k;
	sum /= 2;
	long long dp[45][1000];
	for (i = 0; i <= n; i++){
		for (j = 0; j <= sum; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (i = 1; i <= n; i++){
		for (j = 0; j <= sum; j++){
			dp[i][j] = dp[i - 1][j];
			if (j - i>=0) dp[i][j] += dp[i - 1][j - i];
		}
	}
	cout << dp[n][sum] / 2 << "\n";
	return 0;
}
