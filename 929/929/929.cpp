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

typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;
#define INF 1000000000


void dijkstra(int s, vi *dist, vector<vii> *graph) {
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d == dist->at(u))
			for (int j = 0; j < (int)graph->at(u).size(); j++) {
				ii v = graph->at(u)[j];                       // all outgoing edges from u
				if (dist->at(u) + v.second < dist->at(v.first)) {
					dist->at(v.first) = dist->at(u) + v.second;                 // relax operation
					pq.push(ii(dist->at(v.first), v.first));
				}
			}
	}
}
int main()
{
	int tc,i,j,k;
	cin >> tc;
	while (tc--) {
		vi adj;
		int m, n;
		cin >> m >> n;
		int s = 0, t = m*n - 1;
		vector<vii> graph(t+5, vii());
		for (i = 0; i < m; i++) {
			int a = i*n;
			for (j = 0; j < n; j++) {
				int x;
				cin >> x;
				if (j != 0) {
					graph[a + j - 1].push_back(ii(a + j, x));
				}
				if (j != n - 1)graph[a + j+1].push_back(ii(a + j, x));
				if (i != 0) {
					graph[a + j - n].push_back(ii(a + j, x));
				}
				if (i != m - 1)graph[a + j + n].push_back(ii(a + j, x));
			}
		}
		vi dist(t+5, INF);
		dist[s] = 0;
		dijkstra(s, &dist, &graph);
		cout << dist[t] << "\n";
	}

    return 0;
}

