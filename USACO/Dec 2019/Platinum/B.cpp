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

#define INF 1000000000
#define MOD 1000000007
#define int long long
using namespace std;
class LCA {
public:
	vector<long>p, level;
	vector<vector<long>>dp, adj;
	vector<long> ct;
	vector<int>id;
	int lg = 20;
	long n, root;
	int curr = 0;
	LCA(long long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		ct.resize(n, 0);
		id.resize(n);
		this->n = n;
	}
	void dfs(long long x, vector<bool>& vis) {
		ct[x] = 1;
		id[x] = curr++;
		for (auto t : adj[x]) {
			if (!vis[t]) {
				p[t] = x;
				level[t] = level[x] + 1;
				vis[t] = true;
				dfs(t, vis);
				ct[x] += ct[t];
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
	void addNode(long a, long parent) { //adds new node to existing LCA
		dp[a][0] = parent;
		level[a] = level[parent] + 1;
		for (int j = 1; 1 << j < n; j++) {
			if (dp[a][j - 1] != -1) {
				dp[a][j] = dp[dp[a][j - 1]][j - 1];
			}
		}
	}
};
class segTree {
	struct T {
		int l, r;
		long long sum, lazy;
		void update(long long x) {
			sum += (r - l + 1) * x;
			lazy += x;
		}
	};
public:
	vector<T>tree;
	segTree(int n) {
		tree.resize(n * 4 + 5);
		build(0, n, 1);
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
#define int int
int main()
{
#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 0;
	if (!debug) {
		freopen("snowcow.in", "r", stdin);
		freopen("snowcow.out", "w", stdout);
	}
	int n, q;
	cin >> n >> q;

	LCA* T = new LCA(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		T->add(x, y);
	}
	T->set_root(0);
	T->DP();
	map<int, unordered_set<int>>color;
	segTree* st = new segTree(n);
	//st->update(0, 0, 1);
	//cout << st->query(0, 0) << "\n";
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, c;
			cin >> x >> c;
			x--;
			//if (color[c].empty())color[c].insert(x);
			queue<int>p;
			bool found = false;
			for (auto it : color[c]) {
				if (T->findLCA(it, x) == x)p.push(it);
				if (T->findLCA(it, x) == it)found = true;
			}
			if (!found) {
				while (!p.empty())st->update(T->id[p.front()], T->id[p.front()] + T->ct[p.front()] - 1, -1), color[c].erase(p.front()), p.pop();
				st->update(T->id[x], T->id[x] + T->ct[x] - 1, 1);
				color[c].insert(x);
			}
		}
		else {
			int x;
			cin >> x;
			x--;
			int ret = st->query(T->id[x], T->id[x] + T->ct[x]-1);
			cout << ret << "\n";
		}
	}
	return 0;
}