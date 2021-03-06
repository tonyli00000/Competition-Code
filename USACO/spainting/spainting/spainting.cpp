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
#pragma warning(disable:4996)
#define MOD 1000000007
using namespace std;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("spainting.in", "r", stdin);
		freopen("spainting.out", "w", stdout);
	}
	long long n;
	long long m, k;
	cin >> n >> m >> k;
	vector<long long>dp(n+1);
	dp[0] = 1;
	long long tot = 0,x=1;
	for (int i = 1; i <= n; i++) {
		x *= m;
		x %= MOD;
		tot += dp[i - 1];
		tot %= MOD;
		if (i < k) dp[i] = dp[i - 1] * m%MOD;
		else {
			tot -= dp[i - k];
			tot %= MOD;
			dp[i] = tot * (m - 1) % MOD;
		}
	}
	cout << (MOD + x - dp[n]) % MOD<<"\n";
	return 0;
}