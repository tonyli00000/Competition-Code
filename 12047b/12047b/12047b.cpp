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
long long i, j, k;
#define INF 1000000    // max of distance; may be changed

// ******************** INPUT ***************
vector<vector<pair<long long, long long>> > adj;//Adjacency list is stored in pairs (neighbor,distance)

// ******************** OUTPUT ***************

vector<int>parent;//Used to print out the solution

void SSSP(int n, int source){
	//Initialization
	vector<long long>dist;//distance from the source node
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
	dist.assign(n, INF);
	dist[source] = 0;
	parent.assign(adj.size() + 1, -1);
	pq.push({ source, 0 });
	//Initialization end
	while (!pq.empty()){
		pair<long long, long long> temp = pq.top(); pq.pop();
		int d = temp.first, u = temp.second;
		if (dist[d] < u)continue;
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
int main()
{
	int t;
	cin >> t;
	while (t--){
		adj.clear();
		long long n, m, s, x, p;
		cin >> n >> m >> s >> x >> p;
		adj.resize(n + 1);
		for (i = 0; i < m; i++){
			long long x, y, z;
			cin >> x >> y >> z;

		}
	}
	return 0;
}
