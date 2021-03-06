#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define INF 10000000
#define MOD 1000000007
using namespace std;
vector<int>p;
int getroot(int x) {
	if (p[x] == x)return x;
	return p[x] = getroot(p[x]);
}
void join(int x, int y) {
	int a = getroot(x), b = getroot(y);
	if (a==b)return;
	p[a] = b;
}
long long getdist(long long x, long long y, long long x2, long long y2) {
	return ((x2 - x)*(x2 - x)) + (y2 - y)*(y2 - y);
}
int main()
{
	bool debug = 0;
	if (!debug) {
		freopen("moocast.in", "r", stdin);
		freopen("moocast.out", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector < set<pair<long long, int>>>dist(n);
	vector<int>x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dist[i].insert({ getdist(x[i],y[i],x[j],y[j]),j });
		}
	}

	long long l = 1, r = 25000LL * 25000LL * 2LL+5,minn=r+1;
	p.resize(n);
	while (l <= r) {
		long long mid = (l + r) / 2;
		for (int i = 0; i < n; i++) p[i] = i;
		for (int i = 0; i < n; i++) {
			for (auto it : dist[i]) {
				if (it.first > mid)break;
				join(i, it.second);
			}
		}
		int a = getroot(0);
		bool solved = true;
		for (int i = 1; i < n; i++) {
			if (getroot(i) != a) {
				solved = false;
				break;
			}
		}
		if (solved)r = mid - 1,minn=min(minn,mid);
		else l = mid + 1;
	}
	cout << minn << "\n";
	return 0;
}