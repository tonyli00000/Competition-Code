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
int dp[705][705][2],n;
bool a[705][705];
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int solve(int x, int y, bool root) { //1=left, 0=right
	if (x > y)return 1;
	if (dp[x][y][root] != -1)return dp[x][y][root];
	for (int i = x; i <= y; i++) {
		if (solve(x, i - 1, false) && solve(i + 1, y, true)) {
			if (root && x && !a[x - 1][i])continue;
			if (!root && y + 1 < n && !a[i][y + 1])continue;
			dp[x][y][root] = true;
			return true;
		}
	}
	dp[x][y][root] = false;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<long long>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	memset(a, false, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(x[i], x[j]) > 1)a[i][j] = true, a[j][i] = true;
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		if (solve(0, i - 1, 0) && solve(i + 1, n - 1, 1))cout << "Yes\n", exit(0);
	}
	cout << "No\n";
	return 0;
}