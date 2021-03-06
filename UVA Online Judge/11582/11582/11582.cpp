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
#define MAXN 1005
#define push(a,b) a.push_back(b)
using namespace std;


long long modex(unsigned long long x, unsigned long long y, unsigned long long mod) {
	unsigned long long a = 1, t = x;
	while (y) {
		if (y % 2 == 1)a = ((a%mod)*(t%mod)) % mod;
		t = ((t%mod)*(t%mod)) % mod;
		y /= 2;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>s[MAXN];
	for (int i = 2; i < 1001; i++) {
		push(s[i], 0);
		push(s[i], 1);
		push(s[i], 1);
		int a = 1, b = 1, m = (a + b) % i;
		while (true) {
			if (m == 1 && b == 0)break;
			push(s[i], m);
			a = b; b = m;
			m = ((a%i) + (b%i)) % i;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		unsigned long long x, y, z;
		cin >> x >> y >> z;
		if (z == 1)cout << 0 << "\n";
		else {
			cout << s[z][modex(x, y, s[z].size() - 1)] << "\n";
		}
	}
	return 0;
}