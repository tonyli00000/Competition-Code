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
#pragma warning(disable:4996)
vector<int>p;

void init() {
	for (int i = 1; i < maxx; i++) {
		par[i] = -1;
	}
}

int Find(int node) {
	return par[node] < 0 ? node : (par[node] = Find(par[node]));
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (par[x] > par[y]) /// size(x) = -par[x] < size(y) = -par[y]
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int n, q, ans[maxx];
vector < pair < pair <int, int>, pair <int, int> > > v;


int main() {
	bool debug = 1;
	if (!debug) {
		freopen("mootube.in", "r", stdin);
		freopen("mootube.out", "w", stdout);
	}
	init();
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.pb({ { c, 1 },{ a, b } });
	}
	for (int i = 1; i <= q; i++) {
		int k, vv;
		cin >> k >> vv;
		v.pb({ { k, 0 },{ vv, i } });
	}
	sort(rall(v));
	for (int i = 0; i < n - 1 + q; i++) {
		if (v[i].F.S == 0) {
			ans[v[i].S.S] = -par[Find(v[i].S.F)];
		}
		else {
			Union(v[i].S.F, v[i].S.S);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] - 1 << endl;
	}
	return 0;
}