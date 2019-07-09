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

#define MAXN 100005

vector<int>num(MAXN),B(MAXN*2+5);
int query(int p) {
	int t = 0;
	for (int i = (p + MAXN); i; i -= (i & -i)) {
		t += B[i];
	}
	return t;
}
void update(int p) {
	for (int i = (p + MAXN); i < 2 * MAXN; i += (i & -i)) {
		B[i]++;
	}
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	long long ans = 0;
	int n, x;
	cin >> n >> x;
	for (int i = 0; i<n; ++i) {
		cin >> num[i];
		if (num[i] >= x)num[i]= 1;
		else num[i] = -1;
	}
	update(0);
	int prefix = 0;
	for (int i = 0; i<n; ++i) {
		prefix += num[i];
		ans += query(prefix);
		update(prefix);
	}
	cout << ans << "\n";
	return 0;
}