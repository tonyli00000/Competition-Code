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
/***************************
Algorithm: DAG Path Counting
Time Complexity:  O (N^2)
Space Complexity: V^2
***************************/

vector<bool>unvisited; //Used to compute the topological order
vector<vector<int>> adj; //adjacency list to store neighbors
vector<int> t; //Used to store the topological order


//Topological Sort function
//Stores result in vector t
//modified dfs
void DFS(int u) {
	unvisited[u] = false;
	for (int i = 0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (unvisited[v]) DFS(v);
	}
	t.push_back(u);
}

//assumes 0 as the source of the graph


long long count_path(int n){
	DFS(0);//Returns reversed sorted array
	//initialization
	vector<long long> dp; //dp[i] stores the number of paths from source to node i
	dp.resize(n + 5, 0);
	dp[0] = 1;
	long long ans = 0;
	//initialization end
	for (int i = t.size() - 1; i >= 0; i--) {//Visits in reverse
		int u = t[i];
		for (int j = 0; j < adj[u].size(); j++)
			dp[adj[u][j]] += dp[u];
		if (!adj[u].size()) ans += dp[u];
	}
	return ans;
}

int main()
{
	return 0;
}

