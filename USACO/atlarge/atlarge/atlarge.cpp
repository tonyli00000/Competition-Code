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

#define INF 90000
using namespace std;
int n;
struct node
{
	int time;
	int pos;
};
int solve(int pos, vector<int>&dist, vector<vector<pair<int, int>>>&adj) {
	queue<node> Q;
	vector<bool> vis(n, false);
	Q.push({ 0,pos });
	vis[pos] = true;
	int ct = 0;
	while (!Q.empty()) {
		int ind = Q.front().pos, t = Q.front().time;
		Q.pop();
		if (dist[ind] <= t) ct++;
		else {
			for (int i = 0; i < adj[ind].size(); i++) {
				if (!vis[adj[ind][i].first]) {
					Q.push({ (t + adj[ind][i].second),adj[ind][i].first });
					vis[adj[ind][i].first] = true;
				}
			}
		}
	}
	return ct;
}
int main() {
	bool debug = 1;
	if (!debug) {
		freopen("atlarge.in", "r", stdin);
		freopen("atlarge.out", "w", stdout);
	}
	int k;
	cin >> n>>k;
	vector<vector<int>>adj(n);
	vector<int>barn(n, 0);
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		barn[x - 1]++;
		barn[y - 1]++;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	vector<bool> vis(n, false);
	queue<int> Q;
	vector<int>dist(n, INF);
	for (int i = 0; i < n; i++) {
		if (barn[i] == 1) {
			dist[i] = 0;
			Q.push(i);
			vis[i] = true;
		}
	}
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int i = 0; i<adj[v].size(); i++) {
			int x = adj[v][i];
			if (!vis[x]) {
				dist[x] = min(dist[x], dist[v] + 1);
				vis[x] = true;
				Q.push(x);
			}
		}
	}
	vector<vector<pair<int, int>>>adj2(n);
	for (int i = 0; i < n; i++) {
		if (barn[i] == 2)continue;
		for (int j = 0; j < adj[i].size(); j++) {
			int v = adj[i][j];
			int x = 1, y = i;
			while (barn[v] == 2) {
				adj2[v].push_back({ i, x });
				int t = adj[v][0] + adj[v][1] - y;
				y = v;
				v = t;
				x++;
			}
			adj2[i].push_back({ v, x });
		}
	}

	cout << solve(k-1, dist, adj2)<<"\n";
	/*
	for (int i = 0; i < n; i++) {
		cout << solve(i, dist, adj2) << "\n";
	}*/
	return 0;
}