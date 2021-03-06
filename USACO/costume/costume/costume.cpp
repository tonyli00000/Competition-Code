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

int dp[505][505];
int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		vector<vector<int>>conflict(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int a = 0; a < n; a++) {
					
					if (a!=j && grid[i][j] == grid[i][a]) {
						conflict[i][j]++;
						conflict[i][a]++;
					}
					if (i!=a && grid[i][j] == grid[a][j]) {
						conflict[i][j]++;
						conflict[a][j]++;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans += conflict[i][j]/2;
			}
		}
		cout << "Case #" << k << ": " << ans/2 << "\n";
	}
	return 0;
}



