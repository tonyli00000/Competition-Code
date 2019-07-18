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

#define MOD 1000000007
using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	int mat[105][105];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}
	long long dp[105][105];
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = i + 1; k < r; k++) {
				for (int l = j + 1; l < c; l++) {
					if (mat[i][j] != mat[k][l]) {
						dp[k][l] += dp[i][j];
						dp[k][l] %= MOD;
					}
				}
			}
		}
	}
	cout << dp[r-1][c-1] << "\n";
	return 0;
}
