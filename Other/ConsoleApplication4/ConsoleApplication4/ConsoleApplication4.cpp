#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;
int cap[500][500], f, s, t;
vector<long> dist;
vector<int> p;
#define INF 60000
void solve(int v, int m) {
	if (v == s) {
		f = m;
		return;
	}
	else {
		if (p[v] != -1) {
			solve(p[v], min(m, cap[p[v]][v]));
			cap[p[v]][v] -= f;
			cap[v][p[v]] += f;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>cow(n+1);

	//init
	for (int i = 0; i <= t; i++) {
		for (int j = 0; j <= t; j++) {
			cap[i][j] = 0;
		}
	}
	s = 0;
	t = n + m + 1;
	//Source node = 0
	//Sink node = N+M+1
	//Construction of Graph
	//Nodes 1->M represent farmers
	//Nodes M+1->M+N represent cows
	
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cap[m + i][t] = x;
		cow[i] = { x,y };
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		cap[0][i] = z;
		for (int j = x; j <= y; j++) {
			cap[i][m + j] = INF;
		}
	}
	
	long long tot = 0;
	while (true) {
		f = 0;
		dist.clear();
		dist.resize(t+1, INF);
		queue<int> q;
		p.assign(t+1, -1);
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)break;
			for (int i = 0; i <= t; i++) {
				if (cap[u][i] > 0 && dist[i] == 60000) {
					dist[i] = dist[u] + 1;
					q.push(i);
					p[i] = u;
				}
			}
		}
		solve(t,INF);
		if (!f)break;
		tot += f;
	}
	cout << tot << "\n";

	return 0;
}