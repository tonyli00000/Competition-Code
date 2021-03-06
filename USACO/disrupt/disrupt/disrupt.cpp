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
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000
#pragma warning(disable:4996)

using namespace std;
map<pair<int, int>, int>path;	
vector<set<long long>>adj;
vector<set<pair<int, long long>>>adj2;
vector<long long>ans;

long long find(int curr,map<long long, long long> &dist, set<long long> &contains) {
	long long minn = INF;
	contains.insert(curr);
	for (auto it = adj2[curr].begin(); it != adj2[curr].end(); it++) {
		if (contains.find(it->first) == contains.end()) {
			minn = min(minn, it->second);
			if (dist.find(it->first) == dist.end()) dist[it->first] = it->second;
			else dist[it->first] = min(dist[it->first], it->second);
		}
	}
	return minn;
}
long long solve(long long curr, map<long long, long long> &dist, set<long long> &contains) {
	long long minn;
	if (adj[curr].empty()) {
		minn = INF;
		for (auto it = adj2[curr].begin(); it != adj2[curr].end(); it++) {
			if (it->first != curr) {
				minn = min(minn, it->second);
				if (dist.find(it->first) == dist.end()) dist[it->first] = it->second;
				else dist[it->first] = min(dist[it->first], it->second);
			}
			}
		contains.insert(curr);
		return minn;
	}
	map<long long, long long> x;
	set<long long> y;

	x.clear();
	y.clear();

	for (auto it = adj[curr].begin(); it != adj[curr].end(); it++) {
		long long a = *it;
		long long pathNum = path[{curr, a}];
		adj[a].erase(curr);
		ans[pathNum] = solve(a, x, y);
	}
	minn=find(curr, x, y);
	y.insert(curr);
	for (auto it = x.begin();it!=x.end();it++) {
		if (y.find(it->first) == y.end()) {
			minn= min(minn, it->second);
			if (dist.find(it->first) ==dist.end())dist[it->first] = it->second;
			else dist[it->first] = min(dist[it->first], it->second);
			
		}
	}
	for (auto it = y.begin(); it != y.end(); it++) {
		contains.insert(*it);
	}
	return minn;
}
int main() {
	bool debug = 0;
	if (!debug) {
		freopen("disrupt.in", "r", stdin);
		freopen("disrupt.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	adj.resize(n + 2);
	adj2.resize(n + 2);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].insert(y);
		adj[y].insert(x);
		path[{x, y}] = i;
		path[{y, x}] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		long long z;
		cin >> x >> y >> z;
		x--;
		y--;
		adj2[x].insert({ y,z });
		adj2[y].insert({ x,z });
	}

	ans.resize(n-1, INF);
	map<long long, long long>x;
	set<long long>y;
	solve(0, x, y);
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == INF)cout << "-1\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}