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
	pq.push({ 0,source });
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

int main() {
	int N, cases = 1;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		adj.clear();
		adj.resize(n + 2);
		int u, v, w;
		for (int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[u].push_back({ v, w });
			adj[v].push_back({ u, w });
		}
		SSSP(n, s);
		if (dist[t] != INF) {
			cout << "Case #" << cases++ << ": " << dist[t];
		}
		else {
			cout << "Case #" << cases++ << ": unreachable";
		}
		cout << "\n";
	}


	return 0;

}