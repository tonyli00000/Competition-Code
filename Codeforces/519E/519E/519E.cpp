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
class LCA {
public:
	vector<long>p, level;
	vector<vector<long>>dp, adj;
	int lg = 20;
	long n, root;
	LCA(long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		this->n = n;
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
	void add(long a, long b) {	// adding path between a and b
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	void set_root(long x) {
		p[x] = -1;
		root = x;
		level.resize(n + 5);
		level[root] = 0;
		vector<bool>vis(n, false);
		vis[root] = true;
		dfs(root, vis);
	}
	void DP() {	// all paths are in; use dp to prepare for future LCA calculation
		long i, j;
		dp.assign(n + 5, vector<long>(lg, -1));
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
	}	// return LCA of a and b
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
};
map<int, int>num;
vector<int>e;
int ct = 0;
LCA* T = new LCA(1);
vector<bool>vis;
void dfs(int x) {
	num[x] = ct++;
	e[x] = num[x];
	for (auto it : T->adj[x]) {
		if (!vis[it]) {
			vis[it] = true;
			dfs(it);
			e[x] = max(e[x],e[it]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	e.resize(n);
	vis.assign(n, false);
	vis[0] = true;
	T = new LCA(n);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		T->add(x, y);
	}
	T->set_root(0);
	T->DP();
	dfs(0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		if (x == y) {
			cout << n << "\n";
			continue;
		}
		int a = T->findLCA(x, y), d = T->findDist(x, y);
		if (d % 2 == 1) {
			cout << 0 << "\n";
			continue;
		}
		if (T->level[x] < T->level[y])swap(x, y);
		int b = T->getAncestor(x, d / 2);
		int c = T->getAncestor(x, d / 2 - 1);
		int t = T->getAncestor(y, T->level[y] - T->level[a] - 1);
		int ans = n;
		if (a == b) {
			ans -= (e[c] - num[c] + 1);
			ans -= (e[t] - num[t] + 1);
		}
		else {
			ans = e[b]-num[b]+1;
			ans -= (e[c] - num[c] + 1);
		}
		cout << ans << "\n";
	}
	return 0;
}