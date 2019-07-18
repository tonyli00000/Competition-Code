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
long long i, j, k;
vector<pair<long long, pair<int, int>>> node;
int p[1005];
long long money[1005];

int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}


void addnode(int i, int j) {
	int x = getroot(i), y = getroot(j);
	p[x] = y;
	p[y] = y;
}
int main()
{
	int n;
	cin >> n;
	for (i = 0; i <= n; i++) {
		p[i] = i;
	}

	int x[1005], y[1005];
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	long long ct = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			node.push_back(make_pair((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]), make_pair(i, j)));
			ct++;
		}
	}
	sort(node.begin(), node.begin() + ct);
	long long cost = 0;
	for (i = 0; i < ct; i++) {
		if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
			cost = max(cost, node[i].first);
			addnode(node[i].second.first, (node[i].second.second));
		}
	}
	cout << cost << "\n";
    return 0;
}

