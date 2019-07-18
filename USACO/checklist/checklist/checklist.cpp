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

#define INF 1000000000000000
using namespace std;

vector<pair<long long, long long>>H(2005),G(2005);
long long i, j, k;

long long dp[2005][2005][2];
long long dist(long long x1, long long y1, long long x2, long long y2) {
	long long x = x2 - x1, y = y2 - y1;
	return x*x + y*y;
}
int main()
{
	long long h, g;
	cin >> h >> g;
	for (i = 0; i < h; i++) {
		long long x, y;
		cin >> x >> y;
		H[i+1]=make_pair(x, y);
	}
	for (i = 0; i < g; i++) {
		long long x, y;
		cin >> x >> y;
		G[i+1]=(make_pair(x, y));
	}
	for (i = 0; i < g + 3; i++) {
		for (j = 0; j < h + 3; j++) {
			dp[i][j][0] = INF;
			dp[i][j][1] = INF;
		}
	}
	dp[1][0][0] = 0;
	for (i = 0; i <= h ; i++) {
		for (j = 0; j <= g; j++) {

			//h[i], g[j], 0---->h[i+1], g[j],0
			long long d = dist(H[i].first, H[i].second, H[i + 1].first, H[i + 1].second);
			dp[i + 1][j][0] = min(dp[i+1][j][0], dp[i][j][0] + d);

			//h[i], g[j], 0---->h[i], g[j+1], 1
			d = dist(H[i].first, H[i].second, G[j + 1].first, G[j + 1].second);
			dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][0] + d);

			//h[i], g[j], 1---->h[i+1], g[j], 0
			d = dist(G[j].first, G[j].second, H[i + 1].first, H[i + 1].second);
			dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + d);

			//h[i], g[j], 1---->h[i], g[j+1], 1
			d = dist(G[j].first, G[j].second, G[j + 1].first, G[j + 1].second);
			dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + d);
		}
	}
	cout << dp[h][g][0] << "\n";
    return 0;
}

