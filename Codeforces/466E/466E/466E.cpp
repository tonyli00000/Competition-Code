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
#define INF 10000000
#define MOD 1000000007
#define MAXN 100005
using namespace std;
vector<int>p(MAXN);
vector<vector<int>>adj(MAXN);
vector<vector<pair<int, int>>>query(MAXN);
vector<int>deg(MAXN);
int getroot(int x) {
	if (p[x] == x)return x;
	return p[x]=getroot(p[x]);
}
void dfs(int x,vector<bool>&vis) {
	vis[x] = true;
	for (auto t : adj[x]) {
		dfs(t,vis);
	}
	for (int i = 0; i < query[x].size(); i++) {
		auto it = query[x][i];
		if (vis[it.first])deg[it.second]++;
	}
	vis[x] = false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	int ct = 0;
	vector<pair<int, int>>T;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x;
		if (x == 1) {
			cin >> y >> z;
			p[y] = z;
			adj[z].push_back(y);
			continue;
		}
		if (x == 2) {
			cin >> y;
			T.push_back({ getroot(y),y });
		}
		else {
			cin >> y >> z;
			auto it = T[z - 1];
			query[y].push_back({ it.first,ct });
			query[it.second].push_back({ y,ct });
			ct++;
		}
	}
	vector<bool>vis(n + 5, false);
	for (int i = 1; i <= n; i++) {
		if (p[i] == i)dfs(i, vis);
	}
	for (int i = 0; i < ct; i++) {
		if (deg[i] == 2)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}