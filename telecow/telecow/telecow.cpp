/*
ID:tonyli21
PROG:telecow
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
#define INF 100000000
#pragma warning(disable:4996)

using namespace std;
int n, s, t;
int gap[400], d[400];
vector<vector<int>>cap(400, vector<int>(400, 0)), graph(400, vector<int>(400, 0)), save(400, vector<int>(400, 0));
int solve(int u, int flow){
	if (u == t)return flow;
	int i, ans = 0;
	for (i = 1; i <= 2 * n; i++)
		if (cap[u][i] && d[u] == d[i] + 1){
			int x = solve(i, min(cap[u][i], flow - ans));
			ans += x;
			cap[u][i] -= x;
			cap[i][u] += x;
			if (ans == flow)return ans;
		}
	if (d[s] >= 2 * n)return ans;
	if (!(--gap[d[u]]))
		d[s] = 2 * n;
	gap[++d[u]]++;
	return ans;
}
int maxflow()
{
	int tot = 0;
	cap = graph;
	for (int i = 0; i < 400; i++){
		gap[i] = 0;
		d[i] = 0;
	}
	for (gap[0] = 2 * n; d[s]<2 * n;)
		tot += solve(s, INF);
	return tot;
}
int main()
{
	freopen("telecow.in", "r", stdin);
	freopen("telecow.out", "w", stdout);
	int m, i, j, k;
	bool flag = 1;
	cin >> n >> m >> s >> t;
	s *= 2;
	t = t * 2 - 1;
	for (i = 1; i <= n; i++)
		graph[2 * i - 1][2 * i] = 1;
	for (i = 1; i <= m; i++){
		cin >> j >> k;
		graph[2 * j][2 * k - 1] = graph[2 * k][2 * j - 1] = INF;
	}
	k = maxflow();
	cout << k << "\n";
	save = cap;
	for (i = 1; i <= n; i++)
		if (!save[2 * i - 1][2 * i] && i != s / 2 && i != (t + 1) / 2){
			graph[2 * i - 1][2 * i] = 0;
			if (maxflow() + 1 == k){
				save = cap;
				--k;
				if (flag){
					cout << i;
					flag = false;
				}
				else cout << " "<<i;
			}
			else graph[2 * i - 1][2 * i] = 1;
		}
	cout << "\n";
	return 0;
}

