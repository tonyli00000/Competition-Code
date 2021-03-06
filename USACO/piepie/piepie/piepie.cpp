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
#define MOD 1000000007
using namespace std;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("piepie.in", "r", stdin);
		freopen("piepie.out", "w", stdout);
	}
	queue<long long>q;
	long long n, d;
	cin >> n >> d;
	long long i;
	vector<long long>dist(2*n, -1);
	vector<long long>bessie(n * 2), elsie(n * 2);
	for (i = 0; i < n * 2; i++) {
		cin >> bessie[i] >> elsie[i];
		bessie[i] *= -1;
		elsie[i] *= -1;
	}
	multiset<pair<long long, long long>>x, y;
	for (i = 0; i < n; i++) {
		if (!elsie[i]) {
			dist[i] = 1;
			q.push(i);
		}
		else x.insert({ elsie[i],i });
		if (!bessie[n + 1]) {
			dist[n + i] = 1;
			q.push(n + i);
		}
		else y.insert({ bessie[n + i], n + i });
	}
	while (!q.empty()) {
		long long u = q.front(); q.pop();
		if (u < n) {
			while (true) {
				auto it = y.lower_bound(make_pair(bessie[u], 0));
				if (it == y.end() || it->first > bessie[u] + d) break;
				q.push(it->second);
				dist[it->second] = dist[u] + 1;
				y.erase(it);
			}
		}
		else {
			while (true) {
				auto it = x.lower_bound(make_pair(elsie[u], 0));
				if (it == x.end() || it->first > elsie[u] + d) break;
				q.push(it->second);
				dist[it->second] = dist[u] + 1;
				x.erase(it);
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << dist[i] << "\n";
	}
	return 0;
}