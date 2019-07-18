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

#define MAXX 10
#define INF 100000000
int grid[MAXX][MAXX];
vector<vector<int>>dp(2000, vector<int>(2000));
int N;

int solve(int x, int y){
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = -INF;
	int temp;
	for(int i=0;i<N;i++){
		if ((x & (1 << i)) == 0){
			temp = INF;
			for(int j=0;j<N;j++){
				if ((y & (1 << j)) == 0){
					temp = min(temp, grid[i][j] + solve((x | (1 << i)), (y | (1 << j))));
				}
			}
			ret = max(ret, temp);
		}
	}
	return ret;

}
int main()
{
	int t;
	cin >> t;
	while (t--){
		cin >> N;
		for (int i = 0; i < N;i++){
			for (int j = 0; j < N;j++){
				cin >> grid[i][j];
			}
		}
		dp.assign(2000, vector<int>(2000, -1));
		for (int i = 0; i < sizeof(dp); i++){
			for (int j = 0; j < sizeof(dp[0]); j++){
				dp[i][j] = -1;
			}
		}
		dp[(1 << N) - 1][(1 << N) - 1] = 0;
		cout << solve(0, 0) << "\n";
	}

	return 0;
}