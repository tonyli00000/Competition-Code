/*
ID:tonyli21
PROG:tour
LANG:C++11
*/
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

int main(){
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	int n, m;
	map<string, int> cities;
	int dp[105][105], ans;
	vector<vector<bool>>connected(105, vector<bool>(105, false));
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string x;
		cin >> x;
		cities[x] = i;
	}
	for(int i=1;i<=m;i++) {
		string x, y;
		cin >> x >> y;
		connected[cities[x]][cities[y]] = 1;
		connected[cities[y]][cities[x]] = 1;
	}
	dp[1][1] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<j;k++) {
				if (dp[i][k] > 0 && connected[k][j]) dp[i][j] = max(dp[i][k] + 1, dp[i][j]);
			}
			dp[j][i] = dp[i][j];
		}
	}
	ans = 1;
	for(int i=1;i<=n;i++) {
		if (connected[i][n] == 1) ans = max(ans, dp[i][n]);
	}
	cout << ans << "\n";


	return 0;
}