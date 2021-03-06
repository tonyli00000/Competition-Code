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
#define INF 6000000000000
long long findDist(int x1, int y1, int x2, int y2) {
	return pow(x2 - x1,2) + pow(y2 - y1,2);
}
long long findDist(pair<int, int>a, pair<int, int>b) {
	return pow(a.first - b.first,2) + pow(a.second - b.second,2);
}
int main() {
	bool debug = 1;
	if (!debug) {
		freopen("radio.in", "r", stdin);
		freopen("radio.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	int f1, f2, b1, b2;
	cin >> f1 >> f2 >> b1 >> b2;
	string bessie, farmer;
	cin >> farmer >> bessie;
	vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, INF));
	//dp[i][j][k]=best energy with first i farmer moves, first j bessie moves. 
	//k=0:both don't move, k=1: farmer moves, k=2: bessie moves, k=3: both moves
	dp[0][0] = 0;
	vector < pair<int, int>>path1(n+1), path2(m+1);
	path1[0] = { f1,f2 }; path2[0] = { b1,b2 };
	for (int i = 1; i <= n; i++) {
		if (farmer[i - 1] == 'E')path1[i] = { path1[i - 1].first + 1,path1[i - 1].second };
		if (farmer[i - 1] == 'W')path1[i] = { path1[i - 1].first - 1,path1[i - 1].second };
		if (farmer[i - 1] == 'N')path1[i] = { path1[i - 1].first,path1[i - 1].second + 1 };
		if (farmer[i - 1] == 'S')path1[i] = { path1[i - 1].first,path1[i - 1].second - 1 };
	}
	for (int i = 1; i <= m; i++) {
		if (bessie[i - 1] == 'E')path2[i] = { path2[i - 1].first + 1,path2[i - 1].second };
		if (bessie[i - 1] == 'W')path2[i] = { path2[i - 1].first - 1,path2[i - 1].second };
		if (bessie[i - 1] == 'N')path2[i] = { path2[i - 1].first,path2[i - 1].second + 1 };
		if (bessie[i - 1] == 'S')path2[i] = { path2[i - 1].first,path2[i - 1].second - 1 };
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + findDist(path1[i + 1], path2[j]));//farmer moves
			dp[i][j+1] = min(dp[i][j+1], dp[i][j] + findDist(path1[i], path2[j+1]));//bessie moves
			dp[i + 1][j+1] = min(dp[i + 1][j+1], dp[i][j] + findDist(path1[i + 1], path2[j+1]));//both move
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}