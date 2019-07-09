#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

vector<pair<double, pair<int, int>>> node;

int p[2002];

int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}

void addnode(int i, int j) {
	int x = getroot(i), y = getroot(j);
	if (x == y)return;
	p[x] = y;
	p[y] = y;
}
int main()
{
	long long t, i, j, k;

		long long n,c;
		cin >> n>>c;
		node.clear();
		for (i = 0; i <= n; i++) {
			p[i] = i;
		}
		long long x[2002], y[2002];
		for (i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		long long ct = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				long long dist = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
				if (dist >= c){
					node.push_back(make_pair(dist, make_pair(i, j)));
					ct++;
				}
			}
		}
		sort(node.begin(), node.begin() + ct);
		long long cost = 0;
		for (i = 0; i < ct; i++) {
			if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
				cost += node[i].first;
				addnode(node[i].second.first, (node[i].second.second));
			}

		}
		int root = getroot(0);
		for (i = 0; i < n; i++){
			if (getroot(i) != root)break;
		}
		if (i != n)cout << -1 << "\n";
		else cout << cost << "\n";
	return 0;
}
