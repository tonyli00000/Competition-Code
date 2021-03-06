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
#define INF 10000000
#define MOD 1000000007
#define MAXN 100005
using namespace std;
int b[MAXN];
int ans[MAXN];
int ct[MAXN];
int sq;
int n, m;
int i, j;
unordered_map<int, int>num;
unordered_map<int, int>c;
int curr = 0;
int child[MAXN];
void dfs(int x,vector<vector<int>>&adj,vector<bool>&vis) {
	//cout << x << "\n";
	num[x] = curr++;
	vis[x] = true;
	child[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!vis[adj[x][i]]) {
			dfs(adj[x][i], adj, vis);
			child[x] += child[adj[x][i]];
		}
	}
	return;
}
bool comp(pair<pair<int, int>, pair<int,int>>x, pair<pair<int, int>, pair<int,int>>y) {
	if (x.first.second / sq == y.first.second / sq)return x.first.first < y.first.first;
	return x.first.second / sq < y.first.second / sq;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<int>>adj(n);
	sq = sqrt(n);
	vector<pair<pair<int, int>, pair<int,int>>>query(m);
	vector<int>r(n);
	for (i = 0; i < n; i++) {
		cin >> r[i];
	}
	for (i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<bool>vis(n, 0);
	dfs(0, adj,vis);
	for (int i = 0; i < n; i++) {
		b[num[i]] = r[i];
	}

	for (i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y; 
		x--;
		query[i] = { { num[x],num[x]+child[x]-1 },{i,y} };
	}
	
	sort(query.begin(), query.end(), comp);
	for (i = query[0].first.first; i <= query[0].first.second; i++) {
		ct[b[i]]++;
		c[ct[b[i]]]++;
		j = 0;
	}
	ans[query[0].second.first] = c[query[0].second.second];
	for (i = 1; i < m; i++) {
		int x1 = query[i - 1].first.first, y1 = query[i - 1].first.second, x2 = query[i].first.first, y2 = query[i].first.second;
		if (x2 < x1) {
			for (j = x2; j < x1; j++) {
				ct[b[j]]++;
				c[ct[b[j]]]++;
			}
		}
		if (y2 > y1) {
			for (j = y1 + 1; j <= y2; j++) {
				ct[b[j]]++;
				c[ct[b[j]]]++;
			}
		}
		if (x2 > x1) {
			for (j = x1; j < x2; j++) {
				c[ct[b[j]]]--;
				ct[b[j]]--;
			}
		}
		if (y2 < y1) {
			for (j = y2 + 1; j <= y1; j++) {
				c[ct[b[j]]]--;
				ct[b[j]]--;	
			}
		}
		ans[query[i].second.first] = c[query[i].second.second];
	}
	for (i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}