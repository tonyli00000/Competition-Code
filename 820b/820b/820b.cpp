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
#include <bitset>
using namespace std;

/***************************
Algorithm: Network Flow
Time Complexity:  O (V E^2)
Space Complexity: V^2
***************************/

#define INF 100000000

#define MAX_V 105
//Maximum # of nodes in the graph
int cap[MAX_V][MAX_V], f, s, t;
//s=source, t=sink
//f=change in flow
//cap[][]=available capacity


vector<vector<int>> adj;
//Needs to be initialized in the main() function
//Stores the neighbors of nodes

vector<int> p;
//Stores the parent of a node

//helper function for Network Flow()
//Changes the capacity of the nodes
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, cap[p[v]][v]));
		cap[p[v]][v] -= f;
		cap[v][p[v]] += f;
	}
}

//Returns the maximum flow from source s to sink t
int NetworkFlow() {
	int maxx = 0;
	while (true) {
		//Initialization
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		//Initialization ends
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)break;
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (cap[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)break;

		maxx += f;
	}
	return maxx;
}

int main()
{
	int n, i, j, k;
	int w = 0;
	while (cin >> n && n) {
		int c;
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				cap[i][j] = 0;
			}
		}
		adj.clear();
		adj.resize(n + 2);
		cin >> s >> t >> c;
		s--;
		t--;
		for (i = 0; i < c; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			cap[x - 1][y - 1] += z;
			cap[y - 1][x - 1] += z;
			adj[x - 1].push_back(y - 1);
			adj[y - 1].push_back(x - 1);
		}
		cout << "Network " << ++w << "\n";
		cout << "The bandwidth is ";

		cout << NetworkFlow() << ".\n\n";

	}
	return 0;
}
