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
vector<int>a, b;
int i, j, k;
int dp[1005][1005];
int main()
{
	int n;
	cin >> n;
	for (i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (i = 0; i < n; i++){
		int x;
		cin >> x;
		b.push_back(x);
	}

	for (i = 0; i < 1005; i++){
		for (j = 0; j < 1005; j++){
			dp[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (abs(a[i - 1] - b[j - 1]) <= 4){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else dp[i][j] = max(dp[i][j - 1],dp[i-1][j]);
		}
	}
	cout << dp[n][n] << "\n";
	return 0;
}
