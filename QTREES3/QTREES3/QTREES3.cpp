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
struct edge {
	int x;
	int y;
};
int dfsorder[100005],aa[100005];
class LCA {
public:
	vector<long>p;
	vector<int>level;
	vector<vector<long>>dp, adj;
	int lg = 20;
	long n, root;
	int ct = 0;
	LCA(long n) {
		p.assign(n + 5, -1);
		adj.resize(n + 5);
		this->n = n;
	}
	void dfs(long x, vector<bool>&vis) {
		dfsorder[x] = ct;
		aa[ct++] = x;
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
public:
	vector<int>t;
	int n;
	segTree(int n) {
		t.resize(n * 4 + 5, 0);
		this->n = n;
	}
	void build() {  // build the tree
		for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
	}

	void update(int p, int value) {  // set value at position p
		for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
	}

	int query(int l, int r) {  // sum on interval [l, r)
		int res = 0;
		r++;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = max(res, t[l++]);
			if (r & 1) res = max(res, t[--r]);
		}
		return res;
	}

};
class HLD {
private:
	vector<vector<long>>T;
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
	vector<set<int>>st;
	vector<bool>color;
	HLD(vector<vector<long>>x, vector<int>level, int start = 0) :T(x) {
		head.reserve(T.size());
		chainid.resize(T.size());
		chainPosition.resize(T.size());
		chainSize.reserve(T.size());
		color.assign(x.size(), 0);
		this->level = level;
		//level.resize(T.size(), -1);
		sz.resize(T.size());

		chainSize.push_back(0);
		head.push_back(-1);

		calculateTreeSize(start);
		solve(start);
		st.resize(chainSize.size());
		for (int i = 0; i < chainSize.size(); i++) {
			st[i].clear();
			//st[i]->build(0, chainSize[i], 1);
		}
	}
	//void update(int x, int y) {
	//	while (true) {
	//		if (chainid[x] == chainid[y]) {
	//			if (x == y)break;
	//			st[chainid[y]]->update(chainPosition[x] + 1, chainPosition[y], 1);
	//			break;
	//		}
	//		st[chainid[y]]->update(0, chainPosition[y], 1);
	//		y = head[chainid[y]];
	//	}
	//}
	void update(int x) {
		if (color[x])st[chainid[x]].erase(dfsorder[x]);
		else st[chainid[x]].insert(dfsorder[x]);
		color[x] = !color[x];
	}
	int query(int x) {
		int ans = -1;
		while (x != -1) {
			if (!st[chainid[x]].empty() && *st[chainid[x]].begin() <= dfsorder[x]) {
				ans = aa[*st[chainid[x]].begin()]+1;
			}
			x = head[chainid[x]];
		}
		return ans;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	HLD* hld = new HLD(T->adj, T->level);
	while (q--) {
		int x, y;
		cin >> x >> y;
		y--;
		if (!x) hld->update(y);
		else {
			cout << hld->query(y) << "\n";
		}
	}
	return 0;
}