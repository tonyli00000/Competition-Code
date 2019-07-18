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

using namespace std;
vector<vector<long>>adj;
long counter, ct;
vector<long> dfs_low, dfs_num, S, visited;
long UNVISITED = 10000000000;
map<string, int> name;
map<int, string> node;
void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = counter++; // dfs_low[u] <= dfs_num[u] 
	S.push_back(u); // stores u in a vector based on order of visitation 
	visited[u] = 1;
	for (int j = 0; j < (int)adj[u].size(); j++) {
		long v = adj[u][j];
		if (dfs_num[v] == UNVISITED)
			tarjanSCC(v);
		if (visited[v]) // condition for update 
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		ct++;
		bool first = true;
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			if (!first)cout << ", ";
			first = false;
			cout << node[v];
			if (u == v) {
				cout << "\n";
				break;
			}
		}

	}
}
int main()
{
	long m, n, i, j, k;
	int tc = 0;
	while (cin >> m >> n) {
		if (!m && !n)break;
		if (tc)cout << "\n";
		name.clear();
		node.clear();
		adj.clear();
		adj.resize(m + 5);
		string line;
		//getline(cin, line);
		int ct = 0;
		for (i = 0; i < n; i++) {
			cin >> line;
			if (name.find(line) == name.end()) {
				name[line] = ct++;
				node[ct - 1] = line;
			}
			string s;
			cin >> s;
			if (name.find(s) == name.end()) {
				name[s] = ct++;
				node[ct - 1] = s;
			}
			adj[name[line]].push_back(name[s]);

		}
		dfs_num.assign(m + 5, UNVISITED);
		dfs_low.assign(m + 5, 0);
		visited.assign(m + 5, 0);
		S.clear();
		counter = ct = 0;
		cout << "Calling circles for data set " << ++tc << ":\n";
		for (int i = 0; i < m; i++)
			if (dfs_num[i] == UNVISITED) tarjanSCC(i);
		
	}
	return 0;
}
