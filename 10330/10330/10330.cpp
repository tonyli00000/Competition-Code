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
typedef vector<int> vi;

#define MAX_V 105
#define INF 1000000000

int cap[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;
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
int min(int x, int y, int z) {
	if (x <= y && x <= z)return x;
	else {
		if (y <= x && y <= z)return y;
		else return z;
	}
}
int main()
{
	int n,i,j,k,station[105];
	while (cin >> n) {
		for (i = 0; i <= n+1; i++) {
			for (j = 0; j <= n+1; j++) {
				cap[i][j] = 0;
			}
		}
		for (i = 1; i <= n; i++) cin >> station[i];
		int r;
		cin >> r;
		for (i = 0; i < r; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			cap[x][y] = min(z, station[x], station[y]);
		}
		int x, y;
		cin >> x >> y;
		for (i = 0; i < x; i++) {
			int a;
			cin >> a;
			cap[0][a] = INF;
		}
		for (i = 0; i < y; i++) {
			int a;
			cin >> a;
			cap[a][n + 1] = INF;
		}
		s = 0;
		t = n+1;
		mf = 0;
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
				for (int v = 0; v < n+2; v++)
					if (cap[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
			}
			augment(t, INF);
			if (!f)break;
			mf += f;
		}
		cout << mf << "\n";
	}
	return 0;
}