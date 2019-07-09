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

vector<long long> dist(long long source, vector<vector<long long>> connections) {
	vector<long long> D(connections.size(), -1);

	queue<long long> Q;
	D[source] = 0;
	Q.push(source);
	while (!Q.empty()) {
		long long x = Q.front(); 
		Q.pop();
		for (long y : connections[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				Q.push(y);
			}
		}
	}
	return D;
}
int main() {
	long long b, e, p, n, m,i,j,k;
	cin >> b >> e >> p >> n >> m;
	vector<vector<long long>> neighbor(n, vector<long long>());
	for (i = 0; i < m; i++) {
		long long x, y;
		cin >> x >> y;
		neighbor[x - 1].push_back(y - 1);
		neighbor[y - 1].push_back(x - 1);
	}
	long long ans = 10000000000000000;

	vector<long long>dfromb, dfrome, dfromn;
	dfromb = dist(0, neighbor);
	dfrome = dist(1, neighbor);
	dfromn = dist(n - 1, neighbor);
	for (i = 0; i<n;i++) {
		ans = min(ans, b*dfromb[i]  + e*dfrome[i]  + p*dfromn[i]);
	}
	cout << ans << "\n";
	return 0;
}