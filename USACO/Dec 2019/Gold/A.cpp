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
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007
using namespace std;

#define ALL(a) a.begin(),a.end()

struct edge {
	long long to;
	long long cost;
	long long flow;
};
int main()
{
#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("pump.in", "r", stdin);
		freopen("pump.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;

	vector<vector<edge>>adj(n);
	for (int i = 0; i < m; i++) {
		int x, y, c, f;
		cin >> x >> y >> c >> f;
		x--; y--;
		adj[x].push_back({ y,c,f });
		adj[y].push_back({ x,c,f });
	}

	vector<long double>score(n, 0);
	score[0] = INF;
	queue<pair<pair<int, int>, int>>Q;
	Q.push({ {INF,0},0 });
	while (!Q.empty()) {
		int t = Q.front().second;
		int flow = Q.front().first.first, cost = Q.front().first.second;
		Q.pop();
		for (auto it : adj[t]) {
			int flow2 = min(flow, it.flow);
			int cost2 = cost + it.cost;
			if (1.0 * flow2 / cost2 > score[it.to]) {
				score[it.to] = 1.0 * flow2 / cost2;
				Q.push({ {flow2,cost2},it.to });
			}
		}
	}
	cout << (int)(1e6*score[n - 1])<< "\n";
	return 0;
}