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
#define INF 60000
using namespace std;

int main()
{
	int n,i,j,k;
	cin >> n;
	while (n--){
		int x, y,xi,yi;
		cin >> x >> y;
		map<pair<int, int>, int>ind;
		cin >> xi >> yi;
		ind[make_pair(xi, yi)] = 0;
		int s;
		cin >> s;
		vector<vector<int>>dist(s + 1, vector<int>(s+1, 60000));
		dist[0][0] = 0;
		for (i = 1; i <= s; i++){
			int a, b;
			cin >> a >> b;
			ind[make_pair(a, b)] = i;
			for (auto it = ind.begin(); it->second != i; it++){
				dist[it->second][i] = abs(it->first.first - a) + abs(it->first.second - b);
				dist[i][it->second] = abs(it->first.first - a) + abs(it->first.second - b);
			}
			dist[i][i] = 0;
		}
		for (k = 0; k < s; k++){
			for (i = 0; i < s; i++){
				for (j = 0; j < s; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		vector<vector<int>>dp((1 << 12) + 5, vector<int>(12, -1));
		
		dp[1][0] = 0;
		for (i = 1; i<(1 << s); i++) {
			for (j = 0; j<s; j++) {
				if (dp[i][j] == -1) continue;
				for (k = 1; k<s; k++) {
					if ((i & (1 << k)) != 0) continue;
					int p = (i | (1 << k));
					if (dp[p][k] == -1) dp[p][k] = dp[i][j] + dist[j][k];
					dp[p][k] = min(dp[p][k], dp[i][j] + dist[j][k]);
				}
			}
		}
		int ret = INF;
		for (i = 1; i<s; i++) {
			if (dp[(1 << s) - 1][i]>0) ret = min(ret, dp[(1 << s) - 1][i] + dist[i][0]);
		}
		cout << "The shortest path has length "<<ret << "\n";
	}
	return 0;
}
