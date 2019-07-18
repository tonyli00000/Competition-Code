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
	int n, q,t=0;
	while (cin >> n >> q){
		if (!n &&!q)break;
		cout << "SET " << ++t << ":\n";
		vector<int>num(n+1),temp(n+1);
		for (i = 1; i <= n; i++){
			cin >> num[i];
			temp[i] = num[i];
		}
		int id = 0;
		while(q--){
			int d, m;
			cin >> d >> m;
			vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(m+1, vector<int>(d)));
			for (i = 0; i <= n; i++){
				dp[i][0][0] = 1;
			}
			for (i = 1; i <= n; i++){
				temp[i] =num[i]%d;
			}
			//for (i = 1; i <= n; i++){
			//	if (i != 1){
			//		for (j = 0; j < d; j++){
			//			dp[i][1][j] = dp[i - 1][1][j];
			//		}
			//	}
			//	dp[i][1][temp[i]]++;
			//}
			for (i = 1; i <= n; i++){
				for (j = 1; j <= m; j++){
					for (k = 0; k < d; k++){
						dp[i][j][k] += dp[i - 1][j - 1][(k + d - temp[i]) % d];
						dp[i][j][k] += dp[i-1][j][k];

					}
				}
			}
			cout << "QUERY " << ++id << ": " << dp[n][m][0] << "\n";
		}
	}
	return 0;
}
