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
#define MAXN 5005
using namespace std;
int p[MAXN][MAXN],dp[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i][i];
		dp[i][i] = p[i][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int x = j + i - 1;
			p[j][x] = p[j + 1][x] ^ p[j][x - 1];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int x = j + i - 1;

			dp[j][x] = max(dp[j + 1][x], dp[j][x - 1]);
			dp[j][x] = max(dp[j][x], p[j][x]);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";
	}
	return 0;
}