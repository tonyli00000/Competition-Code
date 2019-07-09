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
vector<bool>unvisited;
vector<vector<int>> adj;
vector<int> t;

void DFS(int u) {
	unvisited[u] = false;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
		if (unvisited[v]) DFS(v);
	}
	t.push_back(u);
}
long long count_path(int n){
	vector<long long> dp;
	dp.resize(n + 5, 0);
	dp[0] = 1;
	long long ans = 0;
	for (int i = t.size() - 1; i >= 0; i--) {
		int u = t[i];
		for (int j = 0; j < adj[u].size(); j++)
			dp[adj[u][j]] += dp[u];
		if (!adj[u].size()) ans += dp[u];
	}
	return ans;
}
int main()
{
	int n;
	bool first = true;
	while (cin >> n){
		if (!first)cout << "\n";
		first = false;
		adj.clear();
		adj.resize(n + 5);
		unvisited.clear();
		unvisited.resize(n + 5,true);
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			for (int j = 0; j < x; j++){
				int y;
				cin >> y;
				adj[i].push_back(y);
			}
		}
		t.clear();
		DFS(0);
		cout<<count_path(n)<<"\n";
	}
	return 0;
}

