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
	int m, n;
	cin >> m >> n;
	vector<vector<bool>>grid(m, vector<bool>(n));
	vector<vector<long>>dp(m, vector<long>(n, 0));
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			char c;
			cin >> c;
			if (c == 'R')grid[i][j] = 0;
			else grid[i][j] = 1;
		}
	}
	dp[0][0] = 1;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			for (k = i + 1; k < m; k++){
				for (int l = j + 1; l < n; l++){
					if (grid[i][j] != grid[k][l])dp[k][l] += dp[i][j];
				}
			}
		}
	}
	cout << dp[m - 1][n - 1] << "\n";
	return 0;
}
