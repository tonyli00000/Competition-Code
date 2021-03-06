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
#define INF 1000000000000
#define MOD 1000000007
using namespace std;

struct node {
	int to;
	int dist;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	long long t;
	cin >> n >> m >> t;
	vector<vector<node>>adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	queue<pair<int,pair<int,int>>>Q;
	Q.push({ 0, {0,0} }); //to, dist, steps
	vector<vector<long long>> dp(n+1, vector<long long>(n+1, INF));
	dp[0][0] = 0; //steps, to
	for (int i = 0; i < n; i++) {
		set<pair<int, pair<int, int>>>add;
		while (!Q.empty()) {
			auto t = Q.front();
			Q.pop();
			for (auto x : adj[t.first]) {
				if (dp[t.second.second+1][x.to] > t.second.first + x.dist) {
					dp[t.second.second + 1][x.to] = t.second.first + x.dist;
					add.insert({ x.to,{ t.second.first + x.dist,t.second.second + 1} });
				}
			}
		}
		for (auto it : add)
			Q.push(it);
	}
	vector<pair<long long, int>>arr(n);
	for (int i = 1; i <= n; i++) {
		arr[i-1] = { dp[i][n - 1],i };
	}
	sort(arr.begin(), arr.end());
	long long ans = arr[0].first;
	long long curr = 1;
	long long i;
	long long minn = INF;
	int index;
	for (i = 1; i < min(t,44800LL); i++) {
		minn = INF;
		for (int j = 0; j < n; j++) {
			if (minn > arr[j].first + (curr*arr[j].second)) {
				minn = min(minn, arr[j].first + (curr*arr[j].second));
				index = j;
			}
		}
		curr++;
		minn %= MOD;
		ans += minn;
		ans %= MOD;
	}
	if (i == t)cout << ans << "\n";
	else {
		long long d = (arr[index].second*((((curr + ((t - 1) % MOD)) % MOD)*((t - curr) % MOD)) % MOD) / 2) % MOD;
		cout << (ans%MOD + d + (arr[index].first*((t - curr) % MOD)) % MOD) % MOD << "\n";
	}
	return 0;
}