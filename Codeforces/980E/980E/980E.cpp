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
	int lg = 22;
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
	void add(long a, long b) {
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
	void DP() {
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
};
vector<bool>vis;
LCA* T = new LCA(1);
void mark(int x, int y) {
	vis[x] = true;
	if (x == y)return;
	mark(T->p[x], y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k = n - k;
	T = new LCA(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		T->add(x, y);
	}
	T->set_root(n-1);
	T->DP();
	vis.assign(n, false);
	vis[n - 1] = true;
	int ct = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (vis[i])continue;
		int t = i;
		for (int j = 20; j >= 0; j--) {
			if (T->dp[t][j] == -1)continue;
			if (!vis[T->dp[t][j]])t = T->dp[t][j];
		}
		if (T->level[i] - T->level[t] + 1 + ct <= k) {
			ct += T->level[i] - T->level[t] + 1;
			mark(i, t);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i])cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}