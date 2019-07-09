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
Algorithm: Bellman Ford (BFS/SSSP), With Negative Cycle detection
Time Complexity:  O (|V||E|)
Space Complexity: V
***************************/


#define INF 1000000    // max of distance; may be changed

// ******************** INPUT ***************
vector<vector<pair<int, int>> > adj;//Adjacency list is stored in pairs (neighbor,distance)

// ******************** OUTPUT ***************
vector<long>dist;//distance from the source node

bool BellmanFord(long n, long source, vector<vector<pair<long, long>>>&adj){
	long i, j, k;
	dist.clear();
	dist.resize(n + 5, 10000000);
	dist[source] = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < adj[j].size(); k++) {
				pair<long, long> v = adj[j][k];
				dist[v.first] = min(dist[v.first], dist[j] + v.second);
			}
		}
	}
	bool negative = false;
	for (i = 0; i < n; i++) {
		for (j = 0; j < adj[i].size(); j++) {
			pair<long, long> v = adj[i][j];
			if (dist[v.first] > dist[i] + v.second)negative = true;
		}
	}
	return negative;
}
int main()
{
	/*int t;
	cin >> t;
	while (t--) {
		long n, m, i, j, k;
		cin >> n >> m;
		vector<vector<pair<long, long>>> adj;
		adj.resize(n + 5);
		int s = 0;
		for (i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[x].push_back(make_pair(y, z));
		}

		if (BellmanFord(n, 0, adj))cout << "possible\n";
		else cout << "not possible\n";
	}*/
	return 0;
}
