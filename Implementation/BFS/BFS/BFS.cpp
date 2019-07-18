/***************************
Algorithm: BFS, Unweighted
Time Complexity: O (E+V)
Space Complexity: V
***************************/


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

#define INF 1000000 //Could Change Depending On Problem

// ******************** INPUT ***************

vector<vector<long long>>adj; //List of the neighbors from each node INPUT

// ******************** OUTPUT ***************

vector<long long>dist; //Stores the distances from the source node OUTPUT
vector<int>parent;//Used to print out the solution OUTPUT


void BFS(int source) {
	queue<long long> Q;
	Q.push(source);
	dist.assign(adj.size() + 1, INF);
	parent.assign(adj.size() + 1, -1);
	dist[source] = 0;

	while (!Q.empty()) {
		long long u = Q.front(); Q.pop();
		for (long long i = 0; i<adj[u].size(); i++) {
			long long v = adj[u][i];
			//if(v==-1)continue; Adjacency matrix
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				parent[v] = u;
				Q.push(v);
			}
		}
	}
}
vector<int> printpath(int last){
	vector<int>x;
	for (int i = last; i != -1; i = parent[i]){
		x.push_back(i);
	}
	return x;
}
int main()
{
	return 0;
}

