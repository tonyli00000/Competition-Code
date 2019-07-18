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
Algorithm: BFS, Unweighted
Time Complexity: O (E log V)
Space Complexity: V
***************************/


#define INF 1000000    // max of distance; may be changed

// ******************** INPUT ***************
vector<vector<pair<int, int>> > adj;//Adjacency list is stored in pairs (neighbor,distance)

// ******************** OUTPUT ***************

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<int>parent;//Used to print out the solution
vector<int>dist;//distance from the source node
void SSSP(int n, int source){
	//Initialization
	dist.clear();
	dist.resize(n, INF);
	dist[source] = 0;
	parent.assign(adj.size() + 1, -1);
	pq.push({ 0, source });
	//Initialization end
	while (!pq.empty()){
		pair<int, int> temp = pq.top(); pq.pop();
		int d = temp.first, u = temp.second;
		for (int j = 0; j < adj[u].size(); j++){
			pair<int, int> v = adj[u][j];
			if (dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				parent[v.first] = u;
				pq.push(make_pair(dist[v.first], v.first));
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
