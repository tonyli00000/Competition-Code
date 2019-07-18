/*
ID:tonyli21
PROG:snail
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

using namespace std;
const int dx[4] = { -1, 0, 0, 1 };
const int dy[4] = { 0, -1, 1, 0 };
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
vector<vector<bool>>vis(150, vector<bool>(150, false)), f(150, vector<bool>(150, false));
int n, B, ans;

void dfs(int x, int y, int fx, int cnt){
	int xx, yy;
	if (f[x][y] || vis[x][y]) return;
	ans = max(cnt, ans);
	vis[x][y] = true;

	xx = x + dx[fx];
	yy = y + dy[fx];
	if (f[xx][yy]){//If obstacle is ahead
		for (int d = 0; d<4; d++)
			dfs(x + dx[d], y + dy[d], d, cnt + 1);
	}
	else dfs(x + dx[fx], y + dy[fx], fx, cnt + 1);
	vis[x][y] = false;
}
int main(){
	freopen("snail.in", "r", stdin);
	freopen("snail.out", "w", stdout);
	cin >> n >> B;
	
	for (int i = 1; i <= n; i++) f[0][i] = f[n + 1][i] = 1;
	for (int i = 1; i <= n; i++) f[i][0] = f[i][n + 1] = 1;
	for (int i = 0; i < B; i++){
		string s;
		cin >> s;
		char r;
		int c;
		stringstream ss(s);
		ss >> r >> c;
		f[c][s[0] - 'A' + 1] = 1;
	}
	ans = 0;
	dfs(1, 1, RIGHT, 1);
	dfs(1, 1, DOWN, 1);
	cout << ans << "\n";
}