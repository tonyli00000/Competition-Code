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

	return 0;
}

