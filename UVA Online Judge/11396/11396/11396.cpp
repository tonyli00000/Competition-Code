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
	while (cin >> t && t) {
		adj.clear();
		adj.resize(t + 5);
		int x, y;
		
		while(cin >> x >> y){
			if (!x && !y)break;
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}

		queue<int> q;
		q.push(0);
		vector<int> color(t, INF);
		bool flag = true;
		while (!q.empty() && flag) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < adj[u].size(); j++) {
				if (color[adj[u][j]] == INF) {
					color[adj[u][j]] = 1 - color[u];
					q.push(adj[u][j]);
				}
				else {
					if (color[adj[u][j]] == color[u]) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
