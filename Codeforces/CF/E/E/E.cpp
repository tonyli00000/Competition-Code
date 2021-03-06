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
#define MOD 998244353
using namespace std;
#pragma warning(disable:4996)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>x(n+5);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<long long>p(n + 5);
	long long a = 1,ret=0;
	for (int i = 0; i <= n; i++) {
		p[i] = a;
		a <<= 1; a %= MOD;
	}
	for (int i = 0; i < n; i++) {
		if (i == n-1) {
			ret += (x[i] % MOD); ret %= MOD;
			continue;
		}
		int a = n - (i + 2), b = 2 - (i+1) + n;
		ret += ((((p[a] % MOD)*(b)) % MOD)*x[i])%MOD;
		ret %= MOD;
	}
	if (n == 1)cout << x[0] << "\n", exit(0);
	cout << ret << "\n";
	return 0;
}