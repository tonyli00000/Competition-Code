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

long long solve(int amount,int n){
	vector<vector<long long>>dp(amount + 2,vector<long long>(n+2,0));
	for (int i = 0; i <= amount; i++){
		for (int j = 1; i+j<=amount&&j <= 26; j++){
			for (int k = 1; k <= n; k++){
				dp[i + j][k] += (dp[i][k - 1] + 1);
			}
		}
	}
	return dp[amount][n];
}
int main()
{
	int l, s,i,j,k;

	while (cin >> l >> s){
		if (!l && !s)break;
		cout << solve(s, l) << "\n";
	}
	return 0;
}
