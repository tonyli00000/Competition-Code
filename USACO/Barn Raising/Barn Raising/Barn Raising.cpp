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
#pragma warning(disable:4996)

#define INF 10000000
#define MOD 1000000007
using namespace std;
vector<vector<int>>adj;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, l;
	cin >> n >> k >> l;
	vector<int>c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	adj.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	long long maxx = 0;
	for (int i = 0; i < n; i++) {
		long long curr = c[i];
		vector<bool>vis(n, false);
		queue<int>Q;
		Q.push(i);
		while (!Q.empty()) {
			int t = Q.front(); Q.pop();
			vis[t] = true;
			for (auto it : adj[t]) {
				if (!vis[it]) {
					vis[it] = true;
					for (auto jt : adj[it]) {
						if (!vis[jt]) {
							Q.push(jt);
							curr += c[jt];
							vis[jt] = true;
						}
					}
				}
			}
		}
		maxx = max(curr, maxx);
	}
	cout << maxx << "\n";
	return 0;
}