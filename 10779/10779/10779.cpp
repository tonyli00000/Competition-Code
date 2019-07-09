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

int cap[40][40], flow[40][40];
int bottleneck[40], pre[40];
int main()
{
	int t, c=0, n,m,k;
	int i, j;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int T = n+m + 1;  
		for (i = 0; i < 40; i++){
			for (j = 0; j < 40; j++){
				cap[i][j] = 0;
				flow[i][j] = 0;
			}
		}
		int x;
		for (int i = 1; i <= n; i++) {
			cin >> k;
			for (int j = 1, x; j <= k; j++) {
				cin >> x;
				cap[i][n+x]++;
			}
		}
		for (i = 2; i <= n; i++) {
			for (j = n + 1; j <= n+m; j++) {
				if (cap[i][j]) --cap[i][j];
				else cap[j][i] = 1;       
			}
		}
		for (int i = n + 1; i <= n+m; i++)
			cap[i][T] = 1;

		int ans = 0;
		while (true) {
			for (i = 0; i < 40; i++){
					bottleneck[i] = 0;
			}
			queue<int> Q;
			Q.push(1);
			bottleneck[1] = 9999999;

			while (!Q.empty() && !bottleneck[T]) {
				int cur = Q.front(); Q.pop();
				for (int nxt = 1; nxt <= T; ++nxt) {
					if (bottleneck[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
						Q.push(nxt);
						pre[nxt] = cur;
						bottleneck[nxt] = min(bottleneck[cur], cap[cur][nxt] - flow[cur][nxt]);
					}
				}
			}
			if (bottleneck[T] == 0) break;

			for (int cur = T; cur != 1; cur = pre[cur]) {
				flow[pre[cur]][cur] += bottleneck[T];
				flow[cur][pre[cur]] -= bottleneck[T];
			}
			ans += bottleneck[T];
		}
		cout << "Case #" << ++c << ": " << ans << "\n";
	}
}