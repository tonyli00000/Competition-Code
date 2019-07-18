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

vector<pair<long long, pair<int, int>>> node;

int p[1005];

int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}

void addnode(int i, int j) {
	int x = getroot(i), y = getroot(j);
	p[x] = y;
}
int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		int n,r;
		cin >> n>>r;
		node.clear();
		for (i = 0; i <= n; i++) {
			p[i] = i;
		}
		int x[1005], y[1005];
		long state;
		for (i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			for (j = 0; j < i; j++) {
				if ((double)sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])>r))state++;
			}
		}
		long long ct = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				node.push_back(make_pair(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])), make_pair(i, j)));
				ct++;
			}
		}
		sort(node.begin(), node.begin() + ct);
		double cost = 0;
		for (i = 0; i < ct; i++) {
			if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
				cost += node[i].first;
				addnode(node[i].second.first, (node[i].second.second));
			}
		}
		cout << fixed << setprecision(0) << cost << "\n";
	}
	return 0;
}
