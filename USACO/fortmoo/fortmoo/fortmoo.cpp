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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;
int i, j, k;
int main(){
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<char>>grid(n + 2,vector<char>(m+2));
	vector<vector<int>>ct(n + 2, vector<int>(m + 2, 0));
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			cin >> grid[i][j];
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			ct[i][j] = ct[i - 1][j];
			if (grid[i][j] == 'X')ct[i][j]++;
		}
	}
	int ans = -1;
	for (i = 1; i <= n; i++){
		for (j = i; j <= n; j++){
			int x = 0, y = 0;
			for (k = 1; k <= m; k++){
				if (ct[j][k] - ct[i - 1][k]==0){
					x = max(x, k);
					y = x;
					while (x < m && grid[i][x + 1] == '.'&& grid[j][x + 1] == '.'){
						x++;
						if (ct[j][x] - ct[i - 1][x] == 0) y = x;
					}
					ans = max(ans, (j - i + 1)*(y - k + 1));
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}