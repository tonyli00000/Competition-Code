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

int main()
{
	long long n, e, i, j, k;
	vector<vector<int>>neighbor;
	vector<long long>quality;
	cin >> n >> e;
	neighbor.resize(n + 2);
	quality.resize(n + 2);
	//for (i = 0; i < 1005; i++) {
	//	for (j = 0; j < 1005; j++) {
	//		dist[i][j] = 1000000000000000000;
	//		best[i][j] = -1;
	//	}
	//}
	for (i = 0; i < n; i++) {
		long long  d;
		cin >> quality[i] >> d;
		for (j = 0; j < d;j++) {
			int nei;
			cin >> nei;
			neighbor[i].push_back(nei-1);
		}
	}
	vector<long long>p;
	for (int i = 0; i < n; i++) {
		p.push_back(i);
	}
	sort(p.begin(), p.end(), [&](int x, int y) {
		return quality[x] < quality[y];
	});
	long long dist[1005];
	for (i = 0; i <= n + 2; i++) {
		dist[i] = 0;
	}
	long long ans = 0;
	for (int i = n-1; i >=0 ; i--) {
		int u = p[i];
		queue<int> q; o;
		int s[1005];
		for (j = 0; j <= n + 2; j++)
			s[j] = -1;
		q.push(u);
		s[u] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < neighbor[v].size(); i++) {
				int x = neighbor[v][i];
				if (s[x] == -1) {
					s[x] = s[v] + 1;
					q.push(x);
				}
			}
		}

		long long temp = quality[u];
		for (int j = 0; j < n; j++) {
			if (s[j] != -1) {
				temp = max(temp, quality[u] + dist[j] - e * s[j]);
			}
		}
		dist[u] = temp;
		if (temp > ans)ans = temp;
	}
	cout << ans << "\n";
	return 0;
}
