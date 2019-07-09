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
pair<long long, int>dist[1005][1005];	
bool visited[1005];
pair<long long, int> cost[1005];
int main()
{
	long long a, b, n,i,j,k;
	cin >> a >> b >> n;
	for (i = 0; i < 1005; i++) {
		for (j = 0; j < 1005; j++) {
			dist[i][j] = make_pair(100000000, 2000);
		}
	}
	for (i = 0; i < 1005; i++) {
		dist[i][i] = make_pair(0, 0);
	}
	for (i = 0; i < n; i++) {
		long long cost, x;
		vector<int>route;
		cin >> cost >> x;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			route.push_back(y);
			for (int k = 0; k < j; k++) {
				dist[route[k]][route[j]] = min(dist[route[k]][route[j]],make_pair(cost, j - k));
			}
		}
	}
	
	for (i = 0; i < 1005; i++) {
		visited[i] = false;
	}
	for (i = 0; i < 1005; i++) {
		cost[i] = make_pair(100000000, 2000);
	}
	cost[a] = make_pair(0, 0);
	for (int i = 0; i < 1005; i++) {
		int u = -1;
		for (int j = 0; j < 1005; j++) {
			if (visited[j]) {
				continue;
			}
			else if (u == -1 || cost[j] < cost[u]) {
				u = j;
			}
		}
		visited[u] = true;
		for (int j = 0; j < 1005; j++) {
			pair<long long, int> temp = cost[u];
			temp.first += dist[u][j].first;
			temp.second += dist[u][j].second;
			cost[j] = min(cost[j], temp);
		}
	}
	if (cost[b].second <= 1005) {
		cout << cost[b].first << ' ' << cost[b].second << "\n";
	}
	else {
		cout << "-1 -1\n";
	}
    return 0;
}

