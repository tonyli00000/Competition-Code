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
#define INF 10000000000000000
#define MOD 1000000007
#pragma warning(disable:4996)

using namespace std;
vector<vector<int>>adj;
vector<vector<long long>>dp;
void dfs(int x, int y,vector<int>&color) {
	for (auto a : adj[x]) {
		if (a == y)continue;
		dfs(a, x,color);
	}
	for (int i = 0; i < 3; i++) {
		if (color[x] != i && color[x] != -1) continue;
		dp[x][i] = 1;
		for (auto a : adj[x]) {
			if (a == y) continue;
			dp[x][i] *= (dp[a][(i+1)%3] + dp[a][(i+2)%3]);
			dp[x][i] %= MOD;
		}
	}
}

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("barnpainting.in", "r", stdin);
		freopen("barnpainting.out", "w", stdout);
	}
	int n, k;
	cin >> n >> k;
	adj.resize(n);
	dp.resize(n, vector<long long>(3, 0));
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>color(n,-1);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		color[x] = y;
	}
	dfs(0, 0, color);
	cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << "\n";
	return 0;
}
