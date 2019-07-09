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

vector<int>match, vis;
//match: stores the left node if there is a match
//vis: whether node is visited or not

vector<vector<int>>Adj;
//Adjacency list

int Aug(int l) { // return 1 if an augmenting path is found 
	if (vis[l]) return 0; // return 0 otherwise 
	vis[l] = 1;
	for (int j = 0; j < Adj[l].size(); j++) {
		int r = Adj[l][j]; 
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
}
int solve(){
	int MCBM = 0;
	int n, V;
	match.assign(V, -1); // V is the number of vertices in bipartite graph 
	for (int l = 0; l < n; l++) { // n = size of the left set 
		vis.assign(n, 0); // reset before each recursion 
		MCBM += Aug(l);
	}
	return MCBM;
}
int main()
{

	return 0;
}

