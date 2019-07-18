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

bool connected[6000][6000];

int dist[6000],p[6000],cap[6000][6000];
void bfs(int s, int t,int n) {
	queue<int> q;
	q.push(s);
	int i, j;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == t)break;
		for (i = 0; i < n; i++) {
			if (connected[u][i] && dist[i] == 60000) {
				dist[i] = dist[u] + 1;
				q.push(i);
				p[i] = u;
			}
		}
	}
}
int solve(int s,int v,int n) {
	if (v == s) {
		return n;
	}
	else {
		solve(s, p[v], min(n, cap[v][p[v]]));
	}
}

int main()
{
	int m, n,tc=0,i,j,k;
	while (cin >> m >> n) {
		if (!m && !n)break;
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				cap[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			x--;
			y--;
			z--;
			cap[x][y] = z;
			cap[y][x] = z;
		}
		int z;
		int s, t;
		cin >> s >> t >> z;
		for (k = 0; k < m; k++) {
			for (i = 0; i < m; i++) {
				for (j = 0; j < m; j++) {
					cap[i][j] = max(cap[i][j], min(cap[i][k], cap[k][j]));
				}
			}
		}
		int a = z/cap[s - 1][t - 1];
		bool flag = (z%cap[s - 1][t - 1]==0);
		cout << "Scenario #" << ++tc << "\n";
		cout << "Minimum Number of Trips = ";
		if (flag)cout << a << "\n";
		else cout << a + 1 << "\n";
		cout << "\n";
	}
    return 0;
}

