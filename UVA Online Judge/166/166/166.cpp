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

vector<int>t = { 5, 10, 20, 50, 100, 200 };

int main()
{
	int a, b, c, d, e, f;
	int i, j, k;
	vector<int>x(6);
	while (true){
		for (i = 0; i < 6; i++){
			cin >> x[i];
		}
		if (!x[0] && !x[1]&&!x[2]&&!x[3]&&!x[4]&&!x[5])break;
		double y;
		cin >> y;
		int total = y * 100;
		vector<vector<int>>dp(7, vector<int>(505, 600));
		dp[0][0] = 0;
		for (i = 1; i <= 6; i++){
			for (j = 1; j <= x[i-1]; j++){
				for (k = 0; k <= total; k++){
					dp[i][k] = dp[i - 1][k];
					if (k - j*t[i - 1] >= 0){
						dp[i][k] = min(dp[i - 1][k - j*t[i - 1]] + j, dp[i][k]);
						dp[i][k] = min(dp[i][k - j*t[i - 1]]+j, dp[i][k]);
					}
				}
			}
		}
		cout << dp[5][total] << "\n";
	}
	return 0;
}
