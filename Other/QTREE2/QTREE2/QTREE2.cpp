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
	vector<vector<long long>>dp;
	vector<vector<node>>adj;
	vector<long long>dist; //Stores distance to root
	int lg = 20;
	long long n, root;
	LCA(long n) {
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
	void add(int a, int b, long long dist) {
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
	void DP() {
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
	}
	long findDist(long a, long b) {
		long long x = findLCA(a, b);
		return abs(dist[a] - dist[x]) + abs(dist[b] - dist[x]);
	} // return distance between a and b
	long getAncestor(long a, long h) { //Finds the hth ancestor above node a
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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		LCA* T = new LCA(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;long long z;
			cin >> x >> y >> z;
			x--; y--;
			T->add(x, y, z);
		}
		T->set_root(0);
		T->DP();
		string op;
		while (cin >> op && op != "DONE") {
			int x, y, z;
			cin >> x >> y; x--; y--;
			if (op == "DIST")cout << T->findDist(x, y) << "\n";
			else {
				cin >> z;
				z--;
				int l = T->findLCA(x, y);
				int a = T->level[x] - T->level[l], b = T->level[y] - T->level[l];
				if (z <= a)cout << T->getAncestor(x, z) + 1 << "\n";
				else {
					z -= a;
					cout << T->getAncestor(y, b - z)+1 << "\n";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}