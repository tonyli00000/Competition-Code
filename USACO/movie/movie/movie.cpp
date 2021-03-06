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
#define MAXN 25
using namespace std;
vector<vector<long long>>t(MAXN);
int find(int x, int y) {
	int l = -1, r = t[y].size() - 1, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (t[y][mid] <= x) l = mid;
		else r = mid - 1;
	}
	return l;
}
int main()
{
	bool debug = 1;
	if (!debug) {
		freopen("movie.in", "r", stdin);
		freopen("movie.out", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long l;
	cin >> n >> l;
	vector<long long>a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x; cin >> x;
		t[i].resize(x);
		for (int j = 0; j < x; j++) {
			cin >> t[i][j];
		}
	}
	vector<long long>dp(1 << n,-1);
	dp[0] = 0;
	int minn = n + 1;
	for (long long i = 0; i < 1 << n; i++) {
		if (dp[i] == -1)continue;
		if (dp[i] >= l) {
			long long x = i;
			int ct = 0;
			while (x) {
				ct += (x % 2);
				x /= 2;
			}
			minn = min(minn, ct);
		}
		for (int j = 0; j < n; j++) {
			if (i&(1 << j))continue;
			int p = find(dp[i], j);
			if (p != -1)dp[i | 1 << j] = max(dp[i | 1 << j], t[j][p] + a[j]);
		}
	}
	if (minn == n + 1)cout << -1 << "\n";
	else cout << minn << "\n";
	return 0;
}