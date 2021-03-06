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
	vector<long>p, level,dfsOrder,out;
	vector<vector<long>>dp, adj;
	int lg = 20;
	long n, root,ct=0;
	LCA(long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		dfsOrder.resize(n);
		out.resize(n);
		this->n = n;
	}
	void dfs(long x, vector<bool>&vis) {
		dfsOrder[x] = ++ct;
		for (auto t : adj[x]) {
			if (!vis[t]) {
				p[t] = x;
				level[t] = level[x] + 1;
				vis[t] = true;
				dfs(t, vis);
			}
		}
		out[x] = ct;
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
		dp.assign(n + 5, vector<long>(lg, 0));
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
	long find(int a, int b) {
		for (int i = lg-1; i >= 0; i--) {
			if (dp[a][i] == -1)continue;
			if (level[dp[a][i]] > level[b])a = dp[a][i];
		}
		return a;
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
			build(l, (r+l)/2, curr<<1);
			build((r+l)/2 + 1, r, curr<<1|1);
			pushUp(curr);
		}
	}

	void update(int LL, int RR, long long x, int curr = 1) {
		int l = tree[curr].l, r = tree[curr].r;
		if (LL <= l && r <= RR)tree[curr].update(x);
		else {
			pushDown(curr);
			int m = (l+r) / 2,ls=curr<<1,rs=curr<<1|1;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>a(n+1);
	LCA* T = new LCA(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		T->add(x, y);
	}
	T->set_root(0);
	T->DP();
	segTree* seg = new segTree(n);
	seg->build(1, n, 1);
	for (int i = 0; i < n; i++) {
		seg->update(T->dfsOrder[i], T->dfsOrder[i], a[i]);
	}
	int root = 0;
	for (int i = 0; i < m; i++) {
		int t;
		long long x, y, z;
		cin >> t;
		if (t == 1) {
			cin >> root;
			root--;
		}
		else {
			if (t == 2) {
				cin >> x >> y >> z; x--; y--;
				int p = T->findLCA(x,y);
				int q = T->findLCA(root, p);
				if (p == q) {
					int aa = T->findLCA(root, x), bb = T->findLCA(root,y);
					seg->update(1, n, z);
					if (aa != root && bb != root) {
						p = aa + bb-p;
						p = T->find(root, p);
						seg->update(T->dfsOrder[p], T->out[p], -z);
					}
				}
				else seg->update(T->dfsOrder[p], T->out[p],z);
			}
			else {
				cin >> x; x--;
				if (x == root)cout << seg->query(1, n)<<"\n";
				else {
					int aa = T->findLCA(root, x);
					if (aa == x) {
						x = T->find(root, x);
						cout << seg->query(1, n) - seg->query(T->dfsOrder[x], T->out[x])<<"\n";
					}
					else cout<< seg->query(T->dfsOrder[x], T->out[x])<<"\n";
				}
			}
		}
	}
	return 0;
}