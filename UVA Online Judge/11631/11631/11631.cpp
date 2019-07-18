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

vector<pair<long, pair<long, long>>> node;

long p[200005];
long getroot(long n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}

int main()
{
	long m, n, i, j;
	while (cin >> m >> n) {
		if (!m && !n)break;
		long long sum = 0;
		long x, y;
		long z;
		for (i = 0; i <= n; i++) {
			p[i] = i;
		}
		for (i = 0; i < n; i++) {
			cin >> x >> y >> z;
			node.push_back(make_pair(z, make_pair(x, y)));
			sum += z;
		}
		long long cost = 0;
		sort(node.begin(), node.end());
		for (i = 0; i < n; i++) {
			long x = getroot(node[i].second.first), y = getroot(node[i].second.second);
			if (x != y) {
				cost += node[i].first;
				p[x] = y;
			}
		}
		cout << sum-cost << "\n";
	}
	return 0;
}