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

//Constants
#define INF 100000000
//Could change based on the problem

#define MAX_V 1005
//Maximum # of nodes in the graph

vector<string>jack, jill;

int cap[MAX_V][MAX_V], f, s, t;
//s=source, t=sink
//f=change in flow
//cap[i][j]=available capacity from node i to j


vector<vector<int>> adj(MAX_V);
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
bool solvable(string x, string y){
	vector<int>jackct(128,0), jillct(128,0);
	for (int i = 0; i < x.length(); i++)
		jackct[x[i]]++;
	for (int i = 0; i < y.length(); i++)
		jillct[y[i]]++;
	for (int i = 0; i<125; i++){
		if (jackct[i]<jillct[i]){
			return false;
		}
	}
	return true;
}
int main()
{
	int n1, n2;
	int i, j, k;
	while (cin >> n1 >> n2){
		for (int i = 0; i < MAX_V; i++){
			for (int j = 0; j < MAX_V; j++){
				cap[i][j] = 0;
			}
		}
		for (i = 0; i < MAX_V; i++){
			adj[i].clear();
		}
		jack.assign(n1 + 1,"");
		jill.assign(n2 + 1, "");
		for (i = 0; i < n1; i++){
			cin >> jack[i];
		}
		for (i = 0; i < n2; i++){
			cin >> jill[i];
		}
		for (i = 1; i <= n1; i++){
			cap[0][i] = 1;
			adj[0].push_back(i);
		}
		for (i = n1 + 1; i <= n1 + n2; i++){
			cap[i][n1 + n2 + 1] = 1;
			adj[i].push_back(n1 + n2 + 1);
		}
		for (i = 0; i<n2; i++){
			for (int j = 0; j<n1; j++){
				if (solvable(jack[j], jill[i])){
					cap[j + 1][n1 + 1 + i] = 1;
					adj[j + 1].push_back(n1 + 1 + i);
				}
			}
		}
		s = 0;
		t = n1 + n2 + 1;
		cout << NetworkFlow() << "\n";
	}
	return 0;
}
