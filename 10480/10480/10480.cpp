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

typedef vector<int> vi;

#define MAX_V 60
#define INF 1000000000

long long cap[MAX_V][MAX_V], mf, f, s, t;
int w[MAX_V];
vector<int> p;
int m, n;
long long min(long long x, long long y) {
	if (x > y)return y;
	else return x;
}
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

void bfs(int ss, int x) {
	queue<int> q;
	w[ss] = x, q.push(ss), p.assign(m + 1, -1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= m; v++)
			if (cap[u][v] > 0 && w[v] != x)
				w[v] = x, q.push(v), p[v] = u;
	}
}
void solve() {
	while (1) {
		bitset<MAX_V> dist(0);
		queue<int> q;
		dist[s] = 0, f = 0, q.push(s), p.assign(m + 1, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int v = 1; v <= m; v++)
				if (cap[u][v] > 0 && dist[v] == 0)
					dist[v] = 1, q.push(v), p[v] = u;
		}
		augment(t, INF);
		if (f == 0)
			break;
	}
}
int main()
{
	long long i, j, k;
	while (cin >> m >> n) {
		if (!m && !n)break;
		for (i = 0; i <= m; i++) {
			for (j = 0; j <= m; j++) {
				cap[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			long long x, y, z;
			cin >> x >> y >> z;
			cap[x][y] = z;
			cap[y][x] = z;
		}
		s = 0;
		t = 1;
		/*mf = 0;
		while (1) {
			f = 0;
			vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < MAX_V; v++)
					if (cap[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
			}
			augment(t, INF);
			if (!f)break;
			mf += f;
		}*/
		solve();
		memset(w, 0, sizeof(w));
		bfs(0, 0);
		bfs(0, 1);
		int sum = 0;
		for (int i = 1; i <= m; i++)
			for (int j = i + 1; j < m; j++)
				if (w[i] != w[j] && (cap[i][j] + cap[j][i] != 0)) {
					cout << i << " " << j << "\n";
					sum += (cap[i][j] + cap[j][i]);
				}
	}
	return 0;
}