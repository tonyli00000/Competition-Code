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
#define INF 1000000000
using namespace std;

vector<vector<int>> adj;
/***************************
Algorithm: Bipartite Graph Check
Time Complexity:  O (V+E)
Space Complexity: V^2
***************************/

#define INF 100000000 //Could Change depending on problem

vector<vector<int>> adj; //adjacency list to store neighbors

//n is the number of nodes
bool CheckBipartite(int n){
	//Initialization
	queue<int> q;
	q.push(0);
	vector<int> color(n, INF);
	bool flag = true;
	//Initialization End
	while (!q.empty() && flag) {
		int u = q.front();
		q.pop();
		for (int j = 0; j < adj[u].size(); j++) {
			if (color[adj[u][j]] == INF) {
				color[adj[u][j]] = 1 - color[u];
				q.push(adj[u][j]);
			}
			else {
				if (color[adj[u][j]] == color[u]) {
					return false;
				}
			}
		}
	}
	return flag;
}
int main()
{
	int t,i,j,k;
	while(cin>>t && t){
		adj.clear();
		adj.resize(t + 5);
		int n;
		cin >> n;
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		if (CheckBipartite(n))cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}
