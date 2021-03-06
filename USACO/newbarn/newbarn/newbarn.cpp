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

#define INF 10000000
#define MOD 1000000007
#define MAXN 100005
using namespace std;
class LCA {
public:
	vector<long>p, level;
	vector<vector<long>>dp, adj;
	int lg = 20;
	long n, root;
	LCA(long n) {
		p.assign(MAXN, -1);
		adj.resize(MAXN);
		dp.resize(MAXN, vector<long>(lg, 0));
		level.assign(MAXN, 0);
		this->n = MAXN;
	}
	void dfs(long x, vector<bool>&vis) {
		for (auto t : adj[x]) {
			if (!vis[t]) {
				p[t] = x;
				level[t] = level[x] + 1;
				vis[t] = true;
				dfs(t, vis);
			}
		}
		return;
	}
	void add(long a, long b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	void set_root(long x) {
		p[x] = -1;
		root = x;
		level.resize(n);
		level[root] = 0;
		vector<bool>vis(n, false);
		vis[root] = true;
		dfs(root, vis);
	}
	void DP() {
		long i, j;
		dp.assign(n, vector<long>(lg, -1));
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
	long findDist(long a, long b) {
		long x = findLCA(a, b);
		return abs(level[a] - level[x]) + abs(level[b] - level[x]);
	} // return distance between a and b
	long getAncestor(long a, long h) { //Finds the hth ancestor above node a
		int x = log2(h);
		for (int i = x; i >= 0; i--) {
			if ((1 << i) <= h) {
				h -= 1 << i;
				a = dp[a][i];
			}
		}
		return a;
	}
	void addNode(long a, long parent) { //adds new node to existing LCA
		dp[a][0] = parent;
		level[a] = level[parent] + 1;
		for (int j = 1; 1 << j < MAXN; j++) {
			if (dp[a][j - 1] != -1) {
				dp[a][j] = dp[dp[a][j - 1]][j - 1];
			}
		}
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("newbarn.in", "r", stdin);
		freopen("newbarn.out", "w", stdout);
	}
	int q;
	cin >> q;
	int n = 0;
	LCA* T=new LCA(100002);
	vector<int>root(100002),r(100002),t(100002), d(100002);
	while (q--) {
		char op;
		int x;
		cin >> op>>x;
		x--;
		if (op == 'B') {
			if (x == -2)root[n] = n++;
			else {
				T->add(x, n);
				T->add(n, x);
				root[n] = root[x];
				T->addNode(n, x);

				int a = root[n];
				int p = T->findDist(n, r[a]), pp = T->findDist(n, t[a]);
				if (p >= d[a] && p >= pp) {
					d[a] = p;
					t[a] = n;
				}
				else if (pp >= d[a] && pp >= p) {
					d[a] = pp;
					r[a] = n;
				}
				n++;
			}
		}
		else {
			if (T->adj[x].size() == 0)cout << 0 << "\n";
			else cout << max(T->findDist(x, r[root[x]]), T->findDist(x, t[root[x]]))<<"\n";
		}
	}
	return 0;
}