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
#include <cmath>
#define INF 10000000
#define MOD 1000000007
using namespace std;
int totient(long long n){
	int ret = n;
	for (long long i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ret -= ret / i;
		}
	}
	if (n > 1)ret -= ret / n;
	return ret;
}
int GCD(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int xx, yy, gcd = GCD(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;
	return gcd;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (m < n - 1)cout << "Impossible\n", exit(0);
	vector<pair<int, int>>out(m);
	int pos = 0;
	for (int i = 2; i <= n; i++) {
		out[pos++] = { 1,i };
	}
	int a, b;
	for (int i = 2; i <= n && pos<m; i++) {
		for (int j = i + 1; j <= n && pos<m; j++) {
			if (GCD(i, j,a,b) == 1) {
				out[pos++] = { i,j };
			}
		}
	}
	if (pos != m)cout << "Impossible\n", exit(0);
	if (pos == m) {
		cout << "Possible\n";
		for (int i = 0; i < m; i++) {
			cout << out[i].first << " " << out[i].second << "\n";
		}
	}
	return 0;
}