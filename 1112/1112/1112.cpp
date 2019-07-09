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
typedef pair < int, int > ii;
#define INF 100000000
vector < ii > g[101];
int N, E, T, M;
int dist[101];
int dijkstra(int src) {
	priority_queue < ii > pq;
	for (int i = 1; i <= N; i++) dist[i] = INF;
	pq.push(ii(src, 0));
	dist[src] = 0;
	int from, to, t, cost;
	while (!pq.empty()) {
		from = pq.top().first;
		cost = pq.top().second;
		pq.pop();

		if (dist[from] == cost && dist[from] <= T)
			for (int i = 0; i < (int)g[from].size(); i++) {
				to = g[from][i].first;
				t = g[from][i].second;
				if (dist[from] + t < dist[to]) {
					dist[to] = dist[from] + t;
					pq.push(ii(to, dist[to]));
				}
			}
	}

	int mices = 0;
	for (int i = 1; i <= N; i++)
		if (dist[i] <= T)
			mices += 1;
	return mices;
}
int main() {
	int tc, t;
	cin >> tc;
	while (tc--) {
		cin >> N >> E >> T;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			g[y].push_back(ii(x, z));
		}
		cout<<dijkstra(E)<<"\n";
		if (tc)cout << "\n";
		for (int i = 1; i <= N; i++) g[i].clear();
	}

	return 0;
}