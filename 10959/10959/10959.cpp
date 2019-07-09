#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define maxN 1001
#define INF 1000000
int n, dist[maxN];
vector<int> adj[maxN];

void BFS() {
	queue<int> Q;
	Q.push(0);
	dist[0] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i<adj[u].size(); i++) {
			int v = adj[u][i];
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
}

int main() {
	int t, m, u, v;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for(int i=0;i<n;i++){
			adj[i].clear();
			dist[i] = INF;
		}
		while (m--) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		BFS();
		for (int i = 1; i < n; i++)
			cout << dist[i] << "\n";
		if (t)cout << "\n";
	}
}