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
#pragma warning(disable:4996)
using namespace std;
struct edge {
	int x;
	int y;
};
class LCA {
public:
	vector<long>p;
	vector<int>level;
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
class segTree {
	struct T {
		int l, r;
		long long sum, lazy;
		void update(long long x) {
			sum += (r - l + 1)*x;
			lazy += x;
		}
	};
public:
	vector<T>tree;
	segTree(int n) {
		tree.resize(n * 4 + 5);
	}
	void pushDown(int curr) {
		long long lazy = tree[curr].lazy;
		if (lazy) {
			int l = curr << 1, r = curr << 1 | 1;
			tree[l].update(lazy);
			tree[r].update(lazy);
			tree[curr].lazy = 0;
		}
	}

	void pushUp(int curr) {
		int l = curr << 1, r = curr << 1 | 1;
		tree[curr].sum = tree[l].sum + tree[r].sum;
	}

	void build(int l, int r, int curr) {
		tree[curr].l = l, tree[curr].r = r, tree[curr].sum = tree[curr].lazy = 0;
		if (r == l) tree[curr].sum = 0;
		else if (r > l) {
			build(l, (r + l) / 2, curr << 1);
			build((r + l) / 2 + 1, r, curr << 1 | 1);
			pushUp(curr);
		}
	}

	void update(int LL, int RR, long long x, int curr = 1) {
		int l = tree[curr].l, r = tree[curr].r;
		if (LL <= l && r <= RR)tree[curr].update(x);
		else {
			pushDown(curr);
			int m = (l + r) / 2, ls = curr << 1, rs = curr << 1 | 1;
			if (LL <= m)update(LL, RR, x, ls);
			if (RR > m)update(LL, RR, x, rs);
			pushUp(curr);
		}
	}

	long long query(int LL, int RR, int curr = 1) {
		int l = tree[curr].l, r = tree[curr].r;
		int m = (l + r) / 2, ls = curr << 1, rs = curr << 1 | 1;
		if (LL <= l && r <= RR)return tree[curr].sum;
		else {
			pushDown(curr);
			long long ret = 0;
			if (LL <= m)ret += query(LL, RR, ls);
			if (RR > m)ret += query(LL, RR, rs);
			return ret;
		}
	}
};
class HLD {
private:
	vector<vector<int>>T;
	void solve(int curr = 0) {
		chainid[curr] = chainSize.size() - 1;
		chainPosition[curr] = chainSize.back();
		chainSize.back()++;

		int maxx = 0;
		int maxxNode = -1;

		for (auto it : T[curr]) {
			if (level[it] > level[curr]) {
				if (maxx < sz[it]) {
					maxx = sz[it];
					maxxNode = it;
				}
			}
		}

		if (maxxNode == -1)return;
		solve(maxxNode);

		for (auto it : T[curr]) {
			if (level[it] > level[curr]) {
				if (it != maxxNode) {
					chainSize.push_back(0);
					head.push_back(curr);
					solve(it);
				}
			}
		}
	}

	void calculateTreeSize(int node) {
		queue<int>Q;
		Q.push(node);
		while (!Q.empty()) {
			int t = Q.front(); Q.pop();
			sz[t] = 1;
			for (auto it : T[t]) {
				if (level[it] > level[t]) {
					sz[t] += sz[it];
					Q.push(it);
				}
			}
		}
	}

public:
	vector<int> head;
	vector<int> chainid;
	vector<int> chainPosition;
	vector<int> chainSize;
	vector<int> level;
	vector<int> sz;
	vector<segTree*>st;
	HLD(vector<vector<int>>x, vector<int>level, int start = 0) :T(x) {
		head.reserve(T.size());
		chainid.resize(T.size());
		chainPosition.resize(T.size());
		chainSize.reserve(T.size());
		this->level = level;
		//level.resize(T.size(), -1);
		sz.resize(T.size());

		chainSize.push_back(0);
		head.push_back(-1);

		calculateTreeSize(start);
		solve(start);
		st.resize(chainSize.size());
		for (int i = 0; i < chainSize.size(); i++) {
			st[i] = new segTree(chainSize[i]);
			st[i]->build(0, chainSize[i], 1);
		}
	}
	void update(int x, int y) {
		while (true) {
			if (chainid[x] == chainid[y]) {
				if (x == y)break;
				st[chainid[y]]->update(chainPosition[x] + 1, chainPosition[y], 1);
				break;
			}
			st[chainid[y]]->update(0, chainPosition[y], 1);
			y = head[chainid[y]];
		}
	}
	int query(int x, int y) {
		int ans = 0;
		while (true) {
			if (chainid[x] == chainid[y]) {
				if (x == y)break;
				ans += st[chainid[y]]->query(chainPosition[x] + 1, chainPosition[y]);
				break;
			}
			ans += st[chainid[y]]->query(0, chainPosition[y]);
			y = head[chainid[y]];
		}
		return ans;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("I.7", "r", stdin);
		freopen("O7.txt", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	vector<vector<int>>adj(n);
	LCA* T = new LCA(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		adj[x].push_back(y); adj[y].push_back(x);
		T->add(x, y);
	}
	T->set_root(0);
	T->DP();
	HLD* hld = new HLD(adj, T->level);

	for (int i = 0; i < m; i++) {
		char c; int x, y;
		cin >> c >> x >> y; x--; y--;
		int a = T->findLCA(x, y);
		if (c == 'P') {
			if (hld->level[y] > hld->level[y])swap(x, y);
			hld->update(a, x); hld->update(a, y);
			//hld->st[hld->chainid[x]]->update(hld->chainPosition[x], hld->chainPosition[x], 1);
		}
		else cout << hld->query(a, x) + hld->query(a, y) << "\n";
		
	}
	return 0;
}