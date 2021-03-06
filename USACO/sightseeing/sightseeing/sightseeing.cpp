#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;
#define INF 60000
struct node {
	int to;
	int dist;
	int fun;
};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, e, m;
	cin >> n >> m >> e;
	vector<vector<node>>adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		adj[a].push_back({ b,c,d });
	}
	if (m == 0 && n == 1)cout << 0 << "\n";
	else if (m == 0)cout << "IMPOSSIBLE\n";

	vector<vector<int>>dp(n + 1, vector<int>(e+1, -INF)); //maximum fun at node i when j energy is spent
	//|V|=100, initialized to -60000 
	queue<int>Q;
	Q.push(0);
	dp[0][0] = 0;
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		//set<int>added;
		for (node x : adj[t]) {
			bool add = false;
			for (int i = 0; i < e; i++) {
				if (i + x.dist > e)continue;
				if (dp[t][i] == -1)continue;
				if (dp[x.to][i + x.dist] < dp[t][i] + x.fun) {
					dp[x.to][i + x.dist] = max(dp[x.to][i + x.dist], dp[t][i] + x.fun);
					add = true;
				}
			}
			if (add) {
				Q.push(x.to);
				//added.insert(x.to);
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i <= e; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	if (ans == -INF)cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
	return 0;
}