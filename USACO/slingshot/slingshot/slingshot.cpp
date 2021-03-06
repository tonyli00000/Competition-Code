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
#pragma warning(disable:4996)

#define INF 10000000
#define MOD 1000000007
using namespace std;

struct slingshot {
	long long l, r, t;
};
bool comp(slingshot x, slingshot y) {
	return x.l < y.l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 0;
	if (!debug) {
		freopen("slingshot.in", "r", stdin);
		freopen("slingshot.out", "w", stdout);
	}
	int n, m;
	cin >> n >> m;
	vector<slingshot>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i].l >> x[i].r >> x[i].t;
	}
	sort(x.begin(), x.end(), comp);
	while (m--) {
		long long a, b;
		cin >> a >> b;
		long long l = 0, r = n - 1;
		while (l < r) {
			long long mid = (l + r) / 2;
			if (x[mid].l > a)r = mid - 1;
			else if (x[mid].l < a)l = mid + 1;
			else l = r = mid;
		}
		long long minn = abs(b - a);
		for (int i = l; i < n&& i <= l + 1700; i++) {
			minn = min(minn, abs(x[i].l - a) + abs(x[i].r - b) + x[i].t);
		}
		for (int i = l; i>=0&& i >= l - 1700; i--) {
			minn = min(minn, abs(x[i].l - a) + abs(x[i].r - b) + x[i].t);
		}
		cout << minn << "\n";
	}
	return 0;
}