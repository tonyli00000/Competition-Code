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
using namespace std;

#define ALL(a) a.begin(),a.end()
vector<int>color;
struct edge {
	int to;
	int dist;
};

class HLD {
private:
	vector<vector<edge>>T;
	vector<int>dist; //Stores distance to root
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
			int d = T[node][i].dist;
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
	vector<unordered_map<int, set<int>>>st;
	HLD(vector<vector<edge>>x, int start = 0) :T(x) {
		head.reserve(T.size());
		chainid.resize(T.size());
		chainPosition.resize(T.size());
		chainSize.reserve(T.size());
		p.resize(T.size());
		dist.resize(T.size() + 5, 0);
		//level.resize(T.size(), -1);
		sz.resize(T.size());
		chainSize.push_back(0);
		head.push_back(-1);
		level.resize(T.size() + 5);
		level[start] = 0;
		dfs(start);
		solve(start);
		top.resize(chainSize.size());
		for (int i = 0; i < T.size(); i++) {
			if (chainPosition[i] == 0)top[chainid[i]] = i;
		}
		st.resize(chainSize.size());
		for (int i = 0; i < color.size(); i++) {
			st[chainid[i]][color[i]].insert(chainPosition[i]);
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
	int getdist(int a, int b) {
		int x = LCA(a, b);
		return abs(dist[a] - dist[x]) + abs(dist[b] - dist[x]);
	}

	bool query(int x, int y, int t) {
		//if (x == y)return st[chainid[y]][t].find(chainPosition[x]) != st[chainid[y]][t].end();

		while (true) {
			if (x == -1 || y == -1)break;

			if (chainid[x] == chainid[y]) {
				//if (x == y)break;
				if (st[chainid[x]].find(t) == st[chainid[x]].end())break;
				if (st[chainid[x]][t].find(chainPosition[x]) != st[chainid[x]][t].end())return true;
				auto it = st[chainid[x]][t].upper_bound(chainPosition[x] - 1);
				if (it != st[chainid[x]][t].end() && *it <= chainPosition[y])return true;
				break;
			}
			//if (LCA(x, y) == y)break;
			if (st[chainid[y]].find(t) != st[chainid[y]].end() && *st[chainid[y]][t].begin() <= chainPosition[y])return true;
			y = head[chainid[y]];
		}
		return false;
	}
};


int main()
{
	//#define int int
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("milkvisits.in", "r", stdin);
		freopen("milkvisits.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	color.resize(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		color[i] = (s[i] == 'H');
	}

	vector<vector<edge>>adj(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back({ y,1 });
		adj[y].push_back({ x,1 });
	}
	HLD T(adj);

	string ret = "";
	for (int i = 0; i < m; i++) {
		int x, y,z;
		char c;
		cin >> x >> y >> c;
		z = (c == 'H');
		x--; y--;
		int k = T.LCA(x, y);
		if (T.query(k, x, z) || T.query(k, y, z))ret += "1";
		else ret += "0";
	}
	cout << ret << "\n";
	return 0;
}