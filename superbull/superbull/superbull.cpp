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

int main()
{
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	long long n;
	cin >> n;
	vector<long long> x;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		x.push_back(y);
	}
	long long ans = 0;
	vector<bool> visited;
	visited.resize(n + 5, false);
	vector<long long> dp;
	dp.resize(n + 5, 0);
	for (int i = 0; i < n; i++) {
		int maximum = -1;
		for (int j = 0; j < n;j++) {
			if (visited[j]) continue;
			if (maximum==-1 || dp[j] > dp[maximum]) {
				maximum=j;
			}
		}
		ans += dp[maximum];
		for (int j = 0; j < n; j++) {
			dp[j] = max(dp[j], x[maximum] ^ x[j]);
		}
		visited[maximum] = true;
	}
	cout << ans << "\n";
	return 0;
}
