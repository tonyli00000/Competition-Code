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
#include <cassert>
#define INF 10000000000
#define MOD 1000000007
using namespace std;

struct node {
	long long to;
	long long time, cost;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long b;
	long long n, m;
	cin >> b >> m >> n;
	vector<vector<node>>adj(n);
	for (long long i = 0; i < m; i++) {
		long long w, x, y, z;
		cin >> w >> x >> y >> z;
		adj[w].push_back({ x,y,z });
		adj[x].push_back({ w,y,z });
	}
	queue<node>Q;
	Q.push({ 0,0,0 });
	long long ans = INF;
	queue<int>check;
	check.push(0);
	vector<bool>vis(n, false);
	vis[0] = true;
	while (!check.empty()) {
		int t = check.front();
		check.pop();
		for (auto it : adj[t]) {
			if (!vis[it.to]) {
				vis[it.to] = true;
				check.push(it.to);
			}
		}
	}
	if (!vis[1]) {
		cout << -1 << "\n"; return 0;
	}
	while (!Q.empty()) {
		node t = Q.front();
		Q.pop();
		if (t.to == 1) ans = min(t.time, ans);
		assert(Q.size() <= n);
		for (node it : adj[t.to]) {
			if (it.cost + t.cost > b || it.time + t.time>ans)continue;
			Q.push({ it.to,it.time + t.time,it.cost + t.cost });
			//cout << t.to << " to " << it.to << " costs " << it.cost + t.cost << " takes " << t.time + it.time << " time \n";
		}
	}
	if (ans == INF)cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}