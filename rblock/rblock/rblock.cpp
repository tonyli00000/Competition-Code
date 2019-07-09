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
#include <list>
using namespace std;
vector<long long> dist(V, 260000000);
class Graph
{
	int V;    // No. of vertices

	// In a weighted graph, we need to store vertex 
	// and weight pair for every edge
	list< pair<int, long long> > *adj;

public:
	Graph(int V);  // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, long long w);

	// prints shortest path from s
	void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, long long> >[V];
}

void Graph::addEdge(int u, int v, long long w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}


void Graph::shortestPath(int src)
{
	vector<int>parent(V+5,-1);
	set< pair<int, int> > setds;

	
	
	setds.insert(make_pair(0, src));
	dist[src] = 0;

	while (!setds.empty()){
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int u = tmp.second;

		list< pair<int, long long> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i){
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight){
				if (dist[v] != 260000000)
					setds.erase(setds.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + weight;
				parent[v] = u;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
	return dist[v - 1];
}
int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++){
		long long x, y, z;
		cin >> x >> y >> z;
		g.addEdge(x, y, z);
	}

	return 0;
}

