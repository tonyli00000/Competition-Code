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

int T, n, s, t, f[10000], F;
queue<int> Q;
vector<int>dist(10000);

int line() {
	int ret = 0, asdf;
	for (double i = 3; i >= 0; i--) {
		int x;
		cin >> x;
		ret += x*(int)pow(10.0, i);
	}
	return ret;
}

int bfs() {
	dist.assign(dist.size(), -1);
	Q = queue<int>();
	dist[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		int p = u;
		int v;
		for (int i = 0; i<4; i++) {
			int d = (int)pow(10.0, (double)i);
			if (p % 10 == 0) v = u + (d * 9);
			else v = u - d;
			if (!f[v] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				if (v == t) return dist[v];
				Q.push(v);
			}
			if (p % 10 == 9) v = u - (d * 9);
			else v = u + d;
			if (!f[v] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				if (v == t) return dist[v];
				Q.push(v);
			}
			p /= 10;
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(f, 0, sizeof f);
		s = line();
		t = line();
		cin >> n;
		for(int i=0;i<n;i++) {
			F = line();
			f[F] = 1;
		}
		if (s == t) {
			cout<<"0\n";
			continue;
		}
		cout << bfs() << "\n";
	}
}