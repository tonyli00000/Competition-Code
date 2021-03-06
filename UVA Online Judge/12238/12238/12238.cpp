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

struct node{
	int to;
	long long dist;
};
class lca_tree {
public:
	vector<long long>p, level;
	vector<vector<long long>>dp;
	vector<vector<node>>adj;
	vector<long long>dist; //Stores distance to root
	int lg = 20;
	long long n, root;
	lca_tree(long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		dist.resize(n + 5);
		this->n = n;
	}
	void dfs(long x, vector<bool>&vis) {
		for (auto t : adj[x]) {
			if (!vis[t.to]) {
				p[t.to] = x;
				level[t.to] = level[x] + 1;
				vis[t.to] = true;
				dist[t.to] = dist[x] + t.dist;
				dfs(t.to, vis);
			}
		}
		return;
	}
	void add(int a, int b,long long dist) {	// add a bidirectional path between a and b
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
	void lca_dp_prep() {	// all paths are in; use dp to prepare for future LCA calculation
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
	long findLCA(long x, long y) {
		if (level[x] < level[y]) swap(x, y);
		int log;
		for (log = 1; 1 << log <= level[x]; log++);
		log--;
		for (int i = log; i >= 0; i--) {
			if (level[x] - (1 << i) >= level[y]) {
				x = dp[x][i];
			}
		}
		if (x == y) return x;
		for (int i = log; i >= 0; i--) {
			if (dp[x][i] != -1 && (dp[x][i] != dp[y][i])) {
				x = dp[x][i], y = dp[y][i];
			}
		}
		return dp[x][0];
	}
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	lca_tree* T = new lca_tree(1);
	while (cin >> n && n) {
		T = new lca_tree(n);
		for (int i = 1; i <= n - 1; i++) {
			long long x, y;
			cin >> x >> y;
			T->add(i, x,y);
		}
		T->set_root(0);
		T->lca_dp_prep();

		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int x, y;
			cin >> x >> y;
			
			long long dist = T->lca_dp_distance(x, y);
			cout << dist;
			if (i != q - 1)cout << " ";
		}
		cout << "\n";
	}
	return 0;
}