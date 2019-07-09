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
int i, j;

#define INF 1000000    // max of distance; may be changed

// ******************** INPUT ***************
vector<vector<pair<int, int>> > adj;//Adjacency list is stored in pairs (neighbor,distance)

// ******************** OUTPUT ***************
vector<int>dist;//distance from the source node

vector<int>parent;//Used to print out the solution

int SSSP(int n, int source, int c){
	//Initialization
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	dist.assign(n, INF);
	dist[source] = 0;
	parent.assign(adj.size() + 1, -1);
	pq.push({ source, 0 });
	//Initialization end
	while (!pq.empty()){
		pair<int, int> temp = pq.top(); pq.pop();
		int u = temp.first;
		for (int j = 0; j < adj[u].size(); j++){
			pair<int, int> v = adj[u][j];
/*			if (u < c){
				if (v.first == v.second + 1 && dist[v.first] > dist[u] + v.second){
					dist[v.first] = dist[u] + v.second;
				}
			}
			else */if (dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				parent[v.first] = u;
				pq.push(make_pair(v.first, dist[v.first]));
			}
		}
	}
	return dist[c - 1];
}
int main()
{
	int n, m, c, k;
	while (cin >> n >> m >> c >> k){
		if (!n && !m && !c && !k)break;
		adj.clear();
		adj.resize(n + 1);
		for (i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			adj[x].push_back({ y, z });
			adj[y].push_back({ x, z });
		}
		cout << SSSP(n+1, k, c) << "\n";
	}
	return 0;
}
