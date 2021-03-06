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
#define INF 10000000000000000
#pragma warning(disable:4996)

using namespace std;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("hayfeast.in", "r", stdin);
		freopen("hayfeast.out", "w", stdout);
	}
	long long n;
	long long m;
	cin >> n >> m;
	vector<long long>flavor(n), spice(n);
	for (long i = 0; i < n; i++) {
		cin >> flavor[i] >> spice[i];
	}
	long long x = 0, y = 0;
	long long sum = 0;
	multiset<long long>curr;
	long long minn = INF;
	for (long i = 0; i < n; i++) {
		sum += flavor[i];
		curr.insert(spice[i]);
		if (sum < m)continue;
		minn = min(minn, *curr.rbegin());
		while (sum - flavor[x] >= m) {
			auto it = curr.find(spice[x]);
			curr.erase(it);
			minn = min(minn, *curr.rbegin());
			sum -= flavor[x++];
		}
	}
	cout << minn << "\n";
	return 0;
}
