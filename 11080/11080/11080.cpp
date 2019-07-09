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
#define INF 1000000000
using namespace std;

vector<vector<int>> adj;

int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, n;
		cin >> m >> n;
		adj.clear();
		adj.resize(m + 5);
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		int ans = 0;
		bool flag = true;
		vector<int> color(m+5, 0);
		color[0] = 1;
		for (i = 0; i < m && flag; i++) {
			if (color[i] == 0) {
				queue<int> q;
				q.push(0);
				int c[2];
				c[0] = 1;
				c[1] = 0;
				while (!q.empty() && flag) {
					int u = q.front();
					q.pop();
					for (int j = 0; j < adj[u].size(); j++) {
						if (color[adj[u][j]]==0) {
							if (color[adj[u][j]] == 1)color[adj[u][j]] == 2;
							if (color[adj[u][j]] == 2)color[adj[u][j]] == 1;
							q.push(adj[u][j]);
							c[color[adj[u][j]]-1]++;
						}
						else {
							if (color[adj[u][j]] == color[u]) {
								flag = false;
								break;
							}
						}
					}
				}
				if (c[0] == 1 && c[1] == 0)ans += 1;
				else ans += min(c[0], c[1]);
			}
		}
		if (!flag)cout << "-1\n";
		else {
			cout << ans << "\n";
		}
	}
	return 0;
}
