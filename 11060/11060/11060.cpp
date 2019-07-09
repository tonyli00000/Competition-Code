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

vector<vector<int>> Adj;
vector<int> ts;
vector<bool> p;
string name[105];
map <string, int> node;
void dfs(int u) {
	p[u] = true;
	for (int j = 0; j < Adj[u].size(); j++) {
		if (!p[Adj[u][j]])dfs(Adj[u][j]);
	}
	ts.push_back(u);
}
void topologicalSort(int V)
{
	vector<int> in_degree(V, 0);
	for (int u = 0; u < V; u++)
	{
		vector<int>::iterator itr;
		for (itr = Adj[u].begin(); itr != Adj[u].end(); itr++)
			in_degree[*itr]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)q.push(i);
	int cnt = 0;
	vector <int> top_order;
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		ts.push_back(u);
		vector<int>::iterator itr;
		for (itr = Adj[u].begin(); itr != Adj[u].end(); itr++)
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++;
	}
}
int main()
{
	int m, n, i, j, k,cn=0;
	string line;
	while (cin >> m) {
		node.clear();
		for (i = 0; i < m; i++) {
			cin >> name[i];
			node[name[i]] = i;
		}
		Adj.clear();
		Adj.resize(m + 5);
		p.clear();
		p.resize(m + 5, false);
		ts.clear();
		cin >> n;
		for (i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			Adj[node[x]].push_back(node[y]);
		}
		topologicalSort(m);
		cout << "Case #" << ++cn << ": Dilbert should drink the beverages in this order: ";
		for (i = 0; i <ts.size(); i++) {
			if (i != 0)cout << " ";
			cout << name[ts[i]];
		}
		cout << ".\n\n";
	}
	return 0;
}