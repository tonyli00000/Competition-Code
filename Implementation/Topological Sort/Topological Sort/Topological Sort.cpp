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
Algorithm: Topological Sort
Time Complexity:  O (V+E)
Space Complexity: V^2
***************************/

#define VISITED 1
#define UNVISITED -1

vector<int>ts; //Stores the topo sorted array
vector<int>dfs_num; //Store whether a node is visited
vector<vector<pair<int, int>>>Adj;//adjacency list to store neighbors

//Helper function
//Modified DFS
void solve(int u){
	dfs_num[u] = VISITED;
	for (int j = 0; j < Adj[u].size(); j++) {
		pair<int, int> v = Adj[u][j];
		if (dfs_num[v.first] == UNVISITED)solve(v.first);
	}
	ts.push_back(u);
}

vector<int> topo_sort(int V){
	ts.clear();
	dfs_num.clear();
	dfs_num.assign(V, UNVISITED);
	for (int i = 0; i < V; i++) {
		if (dfs_num[i] == UNVISITED) 
			solve(i);
	}
	reverse(ts.begin(), ts.end());
	return ts;
}
int main()
{
	return 0;
}
