#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

#define UNVISITED -1
using namespace std;
int dfs_number_counter, root_children, dfs_root;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
vector<vector<int> > adj;

void articulation_point_and_bridge(int u) {
	dfs_low[u] = dfs_num[u] = dfs_number_counter++;
	for (int j = 0; j<adj[u].size(); j++) {
		int v = adj[u][j];
		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfs_root) root_children++;

			articulation_point_and_bridge(v);

			if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}
int main()
{
	int n, i, j, k,tc=0;
	while (cin >> n && n) {
		if (tc)cout << "\n";
		map<string, int> name;
		map<int, string>node;
		adj.clear();
		adj.resize(n + 5);
		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			name[s] = i;
			node[i] = s;
		}
		int m;
		cin >> m;
		for (i = 0; i < m; i++) {
			string x, y;
			cin >> x >> y;
			adj[name[x]].push_back(name[y]);
			adj[name[y]].push_back(name[x]);
		}
		dfs_number_counter = 0;
		dfs_num.assign(n + 5, UNVISITED);
		dfs_low.assign(n + 5, 0);
		dfs_parent.assign(n + 5, 0);
		articulation_vertex.assign(n + 5, 0);
		//ct = 0;
		for (i = 0; i < n; i++) {
			if (dfs_num[i] == UNVISITED) {
				dfs_root = i;
				root_children = 0;
				articulation_point_and_bridge(i);
				articulation_vertex[dfs_root] = (root_children > 1);
			}
		}
		cout << "City map #" << ++tc<<": ";
		int ct = 0;
		vector<string>out;
		for (int i = 0; i < n; i++) {
			if (articulation_vertex[i]) {
				ct++;
				out.push_back(node[i]);
			}
		}
		cout << ct << " camera(s) found\n";
		sort(out.begin(), out.end());
		for (i = 0; i < out.size(); i++) {
			cout << out[i] << "\n";
		}
	}
	return 0;
}

