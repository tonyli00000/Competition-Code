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
void dfs(int u) {
	p[u] = true;
	for (int j = 0; j < Adj[u].size(); j++) {
		if (!p[Adj[u][j]])dfs(Adj[u][j]);
	}
	ts.push_back(u);
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n) {
		if (!m && !n)break;
		Adj.clear();
		Adj.resize(m + 5);
		p.clear();
		p.resize(m + 5, false);
		ts.clear();
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			Adj[x].push_back(y);
		}
		for (i = 1; i <= m; i++) {
			if (!p[i])dfs(i);
		}
		for (i = 0; i <ts.size(); i--) {
			cout << ts[i];
			if (i != 0 && i!=ts.size()-1)cout << " ";
		}
		cout << "\n";
	}
	return 0;
}