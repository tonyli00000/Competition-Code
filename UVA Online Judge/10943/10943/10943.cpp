#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;
long long MOD = 1000000;

long long memo[102][102];
int N, K;

long long rec(int n, int k) {
	if (n == 0 || k == 1) return 1;
	long long res = 0;
	if (memo[n][k] >= 0) return memo[n][k];
	for (int i = 0; i <= n; ++i)
		res = (res + rec(n - i, k - 1)) % MOD;
	return memo[n][k] = res;
}
int main() {
	long long s;
	int n, k;
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			memo[i][j] = -1;
		}
	}
	while (cin >> n >> k) {
		if (n == 0 && k == 0)break;
		else cout << rec(n, k) << "\n";
	}
}