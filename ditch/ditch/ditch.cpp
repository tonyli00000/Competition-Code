/*
ID: tonyli21
PROG: ditch
LANG: C++11
*/
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
#pragma warning(disable:4996)
#define INF 10000000000000
using namespace std;

int i, j, k;
long long cap[205][205];
int s, t;
long long f;
vector<long long> dist;
vector<int> p;
void solve(long long v, long long m) {
	if (v == s) {
		f = m;
		return;
	}
	else {
		if (p[v] != -1) {
			solve(p[v], min(m, cap[p[v]][v]));
			cap[p[v]][v] -= f;
			cap[v][p[v]] += f;
		}
	}
}
int main(){
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (i = 0; i <= m; i++){
		for (j = 0; j <= m; j++){
			cap[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++){
		int x, y;
		long long z;
		cin >> x >> y >> z;
		cap[x][y] += z;
	}
	long long sum = 0;
	s = 1;
	t = m;
	long long tot = 0;
	while (true) {
		f = 0;
		dist.clear();
		dist.resize(m+2, INF);
		queue<int> q;
		p.assign(m+2, -1);
		q.push(s);
		dist[1] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)break;
			for (i = 1; i <=m ; i++) {
				if (cap[u][i] > 0 && dist[i] == INF) {
					dist[i] = dist[u] + 1;
					q.push(i);
					p[i] = u;
				}
			}
		}
		solve(t, INF);
		if (f<=0)break;
		tot += f;
	}
	cout << tot << "\n";
	return 0;
}