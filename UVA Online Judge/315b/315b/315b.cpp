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
int sti(string s) {
	int m = 1, sum = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		sum += m * (s[i] - '0');
		m *= 10;
	}
	return sum;
}

int dfs_number_counter, root_children, dfs_root;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
/*
dfs_num=iteration counter when the vertex u is visited for the ﬁrst time
dfs_low=lowest dfs_num reachable from the current DFS spanning subtree of u
*/
vector<vector<int>> adj;//adjacency list to store neighbors

void articulation_point(int u) {
	dfs_low[u] = dfs_num[u] = dfs_number_counter++;
	for (int j = 0; j<adj[u].size(); j++) {
		int v = adj[u][j];
		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfs_root) root_children++; // special case if u is a root

			articulation_point(v);
			if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

//Function to run and compute the articulation points
void solve(int n){
	//Initialization
	dfs_number_counter = 0;
	dfs_num.assign(n + 5, UNVISITED);
	dfs_low.assign(n + 5, 0);
	dfs_parent.assign(n + 5, 0);
	articulation_vertex.assign(n + 5, 0);
	//End Initialization
	for (int i = 0; i < n; i++) {
		if (dfs_num[i] == UNVISITED) {
			dfs_root = i;
			root_children = 0;
			articulation_point(i);
			articulation_vertex[dfs_root] = (root_children > 1);
		}
	}
}
int main()
{
	int n, i, j, k;
	while (cin >> n && n) {
		string line;
		getline(cin, line);
		adj.clear();
		adj.resize(n + 5);
		while (getline(cin, line) && line[0] != '0') {
			string s;
			stringstream ss(line);
			ss >> s;
			int root = sti(s);
			while (ss >> s) {
				adj[root - 1].push_back(sti(s) - 1);
				adj[sti(s) - 1].push_back(root - 1);
			}
		}
		solve(n);
		int ct = 0;
		for (int i = 0; i<n; i++) if (articulation_vertex[i])ct++;
		cout << ct << "\n";
	}
	return 0;
}
