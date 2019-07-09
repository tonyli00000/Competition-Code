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

string name[105];
class Graph
{
	int V;    // No. of vertices'

			  // Pointer to an array containing adjacency listsList
	list<int> *adj;

public:
	Graph(int V);   // Constructor

					// function to add an edge to graph
	void addEdge(int u, int v);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

// The function to do Topological Sort.
void Graph::topologicalSort()
{
	// Create a vector to store indegrees of all
	// vertices. Initialize all indegrees as 0.
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists to fill indegrees of
	// vertices.  This step takes O(V+E) time
	for (int u = 0; u<V; u++)
	{
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
			in_degree[*itr]++;
	}

	// Create an queue and enqueue all vertices with
	// indegree 0
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	int cnt = 0;

	// Create a vector to store result (A topological
	// ordering of the vertices)
	vector <int> top_order;

	// One by one dequeue vertices from queue and enqueue
	// adjacents if indegree of adjacent becomes 0
	while (!q.empty())
	{
		// Extract front of queue (or perform dequeue)
		// and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// Iterate through all its neighbouring nodes
		// of dequeued node u and decrease their in-degree
		// by 1
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

			// If in-degree becomes zero, add it to queue
			if (--in_degree[*itr] == 0)
				q.push(*itr);

		cnt++;
	}

	// Check if there was a cycle

	// Print topological order
	for (int i = 0; i<top_order.size()-1; i++)
		cout << name[top_order[i]] << " ";
	cout << name[top_order[top_order.size() - 1]] << ".\n";
	cout << "\n";
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	int m, n, i, j, k, cn = 0;
	string line;
	while (cin >> m) {
		map<string, int> node;
		node.clear();
		for (i = 0; i < m; i++) {
			cin >> name[i];
			node[name[i]] = i;
		}
		cin >> n;
		Graph g(m);
		for (i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			g.addEdge(node[x], node[y]);
		}
		cout << "Case #" << ++cn << ": Dilbert should drink the beverages in this order: ";
		g.topologicalSort();
	}
	return 0;
}