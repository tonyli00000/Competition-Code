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
	int to;
	long long dist;
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
	vector<vector<edge>>T;
	vector<long long>dist; //Stores distance to root
	void solve(int curr = 0) {
		chainid[curr] = chainSize.size() - 1;
		chainPosition[curr] = chainSize.back();
		chainSize.back()++;

		int maxx = 0;
		int maxxNode = -1;

		for (auto it : T[curr]) {
			if (level[it.to] > level[curr]) {
				if (maxx < sz[it.to]) {
					maxx = sz[it.to];
					maxxNode = it.to;
				}
			}
		}

		if (maxxNode == -1)return;
		solve(maxxNode);

		for (auto it : T[curr]) {
			if (level[it.to] > level[curr]) {
				if (it.to != maxxNode) {
					chainSize.push_back(0);
					head.push_back(curr);
					solve(it.to);
				}
			}
		}
	}

	void dfs(int node) {
		sz[node] = 1;
		for (int i = 0; i < T[node].size(); i++) {
			int t = T[node][i].to;
			long long d = T[node][i].dist;
			if (t == p[node])continue;
			p[t] = node;
			level[t] = level[node] + 1;
			dist[t] = dist[node] + d;
			dfs(t);
			sz[node] += sz[t];
		}
	}

public:
	vector<int> head; //parent of the top node of the chain
	vector<int> chainid;
	vector<int> chainPosition;
	vector<int> chainSize;
	vector<int> level;
	vector<int> sz;
	vector<int>p;
	vector<int>top; //Top node of the chain
	vector<segTree*>st;
	HLD(vector<vector<edge>>x, int start = 0) :T(x) {
		head.reserve(T.size());
		chainid.resize(T.size());
		chainPosition.resize(T.size());
		chainSize.reserve(T.size());
		p.resize(T.size());
		dist.resize(T.size() + 5,0);
		//level.resize(T.size(), -1);
		sz.resize(T.size());
		chainSize.push_back(0);
		head.push_back(-1);
		level[start] = 0;
		dfs(start);
		solve(start);
		top.resize(chainSize.size());
		for (int i = 0; i < T.size(); i++) {
			if (chainPosition[i] == 0)top[chainid[i]] = i;
		}
		st.resize(chainSize.size());
		for (int i = 0; i < chainSize.size(); i++) {
			st[i] = new segTree(chainSize[i]);
			st[i]->build(0, chainSize[i], 1);
		}
	}
	int LCA(int x, int y) {
		while (chainid[x] != chainid[y]) {
			if (level[top[chainid[x]]] > level[top[chainid[y]]])swap(x, y);
			y = head[chainid[y]];
		}
		if (level[x] > level[y])swap(x, y);
		return x;
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
	int n;
	
	while (cin >> n && n) {
		vector<vector<int>>adj(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y; x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		HLD* hld = new HLD(adj);

		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int x, y;
			cin >> x >> y; x--; y--;
			int rt = T->findLCA(x,y);
			if (T->level[x] < T->level[y])swap(x, y);
			long dist = T->lca_dp_distance(x, y);
			long a = T->lca_dp_ancestor(x, dist / 2);
			
			if(dist%2==0){
				cout << "The fleas meet at " << a+1 << ".\n";
			}
			else {
				cout << "The fleas jump forever between " << min(a, T->p[a])+1 << " and " << max(a, T->p[a])+1 << ".\n";
			}
		}
	}
	return 0;
}