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

using namespace std;

int main() {
	bool debug = 1;
	if (!debug) {
		freopen("feast.in", "r", stdin);
		freopen("feast.out", "w", stdout);
	}
	long long t;
	int a, b;
	cin >> t >> a >> b;
	vector<vector<bool>>dp(t+2, vector<bool>(2, false));
	dp[0][0] = true;
	dp[0][1] = true;
	long long i;
	long long maxx = 0;
	set<long long>curr;
	curr.insert(0);
	for (i = 0; i < t; i++) {
		if (dp[i][0]) {
			if (i + a <= t)dp[i + a][0] = true;
			if (i + b <= t)dp[i + b][0] = true;
			dp[i / 2][1] = true;
		}
	}
	for (i = 0; i < t; i++) {
		if (dp[i][1]) {
			if (i + a <= t)dp[i + a][1] = true;
			if (i + b <= t)dp[i + b][1] = true;
		}
	}
	for (i = t;; i--) {
		if (dp[i][0] || dp[i][1]) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}