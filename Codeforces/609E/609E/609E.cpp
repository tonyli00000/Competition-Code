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
using namespace std;

struct node {
	int to;
	long long dist;
};
class LCA {
public:
	vector<long long>p, level;
	vector<vector<long long>>dp,maxx;
	vector<vector<node>>adj;
	vector<long long>dist; //Stores distance to root
	int lg = 20;
	long long n, root;
	LCA(long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		dist.resize(n + 5);
		maxx.assign(n + 5, vector<long long>(lg, -1)); //Maxx path
		dp.assign(n + 5, vector<long long>(lg, -1));
		this->n = n;
	}
	void dfs(long x, vector<bool>&vis) {
		for (int i = 1; i < lg; i++) {
			if (dp[x][i - 1] != -1) { //Calculates DP
				dp[x][i] = dp[dp[x][i - 1]][i - 1];
				maxx[x][i] = max(maxx[dp[x][i - 1]][i - 1], maxx[x][i - 1]);
			}
		}
		for (auto t : adj[x]) {
			if (!vis[t.to]) {
				p[t.to] = x;
				level[t.to] = level[x] + 1;
				vis[t.to] = true;
				dist[t.to] = dist[x] + t.dist;
				dp[t.to][0] = x;
				maxx[t.to][0] = t.dist;
				dfs(t.to, vis);
			}
		}
		return;
	}
	void add(int a, int b, long long dist) {	// add a bidirectional path between a and b
		adj[a].push_back({ b,dist });
		adj[b].push_back({ a,dist });
	}
	void set_root(long x) {
		p[x] = -1;
		root = x;
		level.resize(n + 5);
		level[root] = 0;
		vector<bool>vis(n, false);
		vis[root] = true;
		dist[root] = 0;
		dfs(root, vis);
	}
	void DP() {	// all paths are in; use dp to prepare for future LCA calculation
		long long i, j;
		dp.assign(n + 5, vector<long long>(lg, -1));
		for (i = 0; i < n; i++) {
			dp[i][0] = p[i];
		}
		for (j = 1; 1 << j < n; j++) {
			for (i = 0; i < n; i++) {
				if (dp[i][j - 1] != -1)dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
	long long getMax(int a, int b) {
		long long ret = 0;
		int h=level[a]-level[b];
		for (int i = 0; h; i++) {
			if (h & 1) {
				ret = max(ret, maxx[a][i]);
				a = dp[a][i];
			}
			h /=2;
		}
		return ret;
	}
	long findLCA(long a, long b) {
		int tmp, log, i;
		if (level[a] < level[b])tmp = a, a = b, b = tmp;
		for (log = 1; 1 << log <= level[a]; log++);
		log--;
		for (i = log; i >= 0; i--) {
			if (level[a] - (1 << i) >= level[b])a = dp[a][i];
		}
		if (a == b)return a;
		for (i = log; i >= 0; i--) {
			if (dp[a][i] != -1 && dp[a][i] != dp[b][i])	a = dp[a][i], b = dp[b][i];
		}
		return p[a];
	}	// return LCA of a and b
	long long lca_dp_distance(long long a, long long b) {
		long long x = findLCA(a, b);
		return abs(dist[a] - dist[x]) + abs(dist[b] - dist[x]);
	} // return distance between a and b
	long lca_dp_ancestor(long a, long h) { // return h-level ancestor of a; -1 if it is outside of tree
		long long x = log2(h);
		for (int i = x; i >= 0; i--) {
			if ((1 << i) <= h) {
				h -= 1 << i;
				a = dp[a][i];
			}
		}
		return a;
	}
};
vector<int>p;
int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}
vector<int>sz;
void addnode(int x,int y) {
	if (sz[x] > sz[y]) {
		p[y] = x;
		sz[x] = max(sz[x], sz[y]+1);
	}
	else {
		p[x] = y;
		sz[y] = max(sz[y], sz[x] + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<long long, pair<int,int>>>edges(m),edges2(m);
	vector<pair<int, int>>a(m);
	for (int i = 0; i < m; i++) {
		long long x, y,z;
		cin >> x >> y >> z; x--; y--;
		edges[i] = { z,{x,y}};
		edges2[i] = edges[i];
		a[i] = { x,y };
	}
	p.resize(n + 5);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	sort(edges.begin(), edges.end());
	//vector<pair<long long, pair<int, int>>>T;
	//MST
	set<pair<int, int>>added;
	long long cost = 0;
	LCA* T = new LCA(n);
	sz.assign(n, 1);
	for (int i = 0; i < m; i++) {
		auto it = edges[i];
		int a = getroot(it.second.first), b = getroot(it.second.second);
		if (a!=b) {
			added.insert({ it.second.first,it.second.second });
			cost += it.first;
			addnode(a, b);
			T->add(it.second.first, it.second.second,it.first);
		}
	}
	T->set_root(0);
	//T->DP();
	for (int i = 0; i < m; i++) {
		if (added.find(a[i]) != added.end())cout << cost << "\n";
		else {
			int x = T->findLCA(a[i].first, a[i].second);
			cout << cost-max(T->getMax(a[i].first,x),T->getMax(a[i].second,x))+edges2[i].first << "\n";
		}
	}
	return 0;
}