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
#define INF -100000000
using namespace std;

int main()
{

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n;
		double p;
		cin >> n >> p;
		vector<int>x(n), y(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		vector<vector<double>>dp(n + 1, vector<double>(25005, INF));

		dp[0][0] = 0.0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n * 250; j++) {
				if (dp[i][j] == INF) continue;

				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				int a = j + min(x[i], y[i]);
				dp[i + 1][a] = max(dp[i + 1][a] * 1.0, dp[i][j] * 1.0 + sqrt(x[i] * x[i] + y[i] * y[i]));
			}
		}
		double sum = 0.0;
		for (int i = 0; i < n; i++) {
			p -= 2.0*(x[i] + y[i]);
			sum += 2.0*(x[i] + y[i]);
		}
		p /= 2;
		double ret = 0.0;
		for (int j = 0; j <= n * 250; j++) {
			if (dp[n][j] == INF || j >= p) continue;
			ret = max(ret, 1.0*min(p, dp[n][j]));
		}
		cout << "Case #" << k << ": ";
		cout << fixed << setprecision(6) << ret * 2.0 + sum << "\n";
	}
	return 0;
}

