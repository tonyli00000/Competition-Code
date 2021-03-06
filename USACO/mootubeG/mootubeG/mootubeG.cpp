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
using namespace std;

int n, q;

vector<int>p;

int find(int node) {
	return p[node]==node ? node : (p[node] = find(p[node]));
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (p[x] > p[y])swap(x, y);
	p[x] += p[y];
	p[y] = x;
}

int main()
{
	vector<pair<pair<int, int>, pair <int, int>>>v;
	bool debug = 1;
	if (!debug) {
		freopen("mootube.in", "r", stdin);
		freopen("mootube.out", "w", stdout);
	}
	
	cin >> n >> q;
	p.resize(n+5, 0);
	vector<int>ans(n+5);
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ { c, 1 },{ a, b } });
	}
	for (int i = 1; i <= q; i++) {
		int x,y;
		cin >> x >> y;
		v.push_back({ { x, 0 },{ y, i } });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1 + q; i++) {
		if (v[i].first.second == 0) {
			ans[v[i].second.second] = -1*p[find(v[i].second.first)];
		}
		else {
			join(v[i].second.first, v[i].second.second);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] - 1 << "\n";
	}
    return 0;
}

