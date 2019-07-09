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
const int inf = 1 << 30;
long long i, j, k,x[100005],y[100005];
map<pair<long long, long long>, long long>coord;
map<long long, vector<long long>>xcoord, ycoord;

long long N;

long long bfs(long long A, long long B, vector< vector<long long> > adj) {
	vector<long long> dist(N+5);
	vector<bool> vis(N+5);
	queue<long long>bfsq;
	bfsq.push(A);
	for (i = 0; i < N + 3; i++) {
		dist[i] = inf;
	}
	dist[A] = 0;
	while (!bfsq.empty()) {
		int u = bfsq.front();
		bfsq.pop();
		for (i = 0; i < adj[u].size();i++) {
			long long v = adj[u][i];
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				bfsq.push(v);
			}
		}
	}
	return dist[B];
}
int main()
{
	long long x1, y1, x2, y2, maxx, maxy;
	cin >> N >> x1 >> y1 >> x2 >> y2;
	for (i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		xcoord[x[i]].push_back(y[i]);
		ycoord[y[i]].push_back(x[i]);
		maxx = max(maxx, x[i]);
		maxy = max(maxy, y[i]);
		coord[make_pair(x[i], y[i])] = i;
	}
	xcoord[x1].push_back(y1);
	xcoord[x2].push_back(y2);
	ycoord[y1].push_back(x1);
	ycoord[y2].push_back(x2);
	coord[make_pair(x1, y1)] = N;
	coord[make_pair(x2, y2)] = N+1;
	x[N] = x1;
	x[N + 1] = x2;
	y[N] = y1;
	y[N + 1] = y2;
	vector<vector<long long>>adj(N+5);
	for (i = 0; i < N+2; i++) {
		for (j = 0; j < xcoord[x[i]].size(); j++) {
			if (xcoord[x[i]][j] != y[i]) {
				adj[i].push_back(coord[make_pair(x[i], xcoord[x[i]][j])]);
			}
		}
		for (j = 0; j < ycoord[y[i]].size(); j++) {
			if (ycoord[y[i]][j] != x[i]) {
				adj[i].push_back(coord[make_pair(ycoord[y[i]][j],y[i])]);
			}
		}
	}
	map<long long,vector<long long>>::iterator a = xcoord.find(x1), b = ycoord.find(y1), c = xcoord.find(x2), d=ycoord.find(y2);
	if (a == xcoord.end() && b == ycoord.end())cout << "-1\n";
	else {
		if (c == xcoord.end() && d == ycoord.end())cout << "-1\n";
		else cout << bfs(N, N + 1, adj) - 1 << "\n";
	}
    return 0;
}

