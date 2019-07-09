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
#define INF 600000
using namespace std;

int main()
{
	int tc,t=0,i,j,k;
	cin >> tc;
	while (tc--){
		int m, n,g[105][105];
		cin >> m >> n;
		for (i = 0; i <= m; i++){
			for (j = 0; j <= m; j++){
				g[i][j] = INF;
			}
		}
		for (i = 0; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			g[x][y] = min(g[x][y],z);
			g[y][x] = g[x][y];
		}
		for (k = 1; k <= m; k++){
			for (i = 1; i <= m; i++){
				for (j = 1; j <= m; j++){
					if (g[i][j] > g[i][k] + g[k][j]){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}
		vector<int> ans;
		for (i = 6; i <= m; i++){
			bool rally = true;
			int p = g[i][1];
			if (p == INF)rally = false;
			else{
				for (j = 2; j <= 5; j++){
					if (g[i][j] != p)rally = false;
				}
			}
			for (j = 6; j <= m; j++){
				if (g[i][j] == INF && j!=i){
					rally = false;
					break;
				}
			}
			if (rally)ans.push_back(i);
		}
		cout << "Map " << ++t << ": ";
		if (ans.empty())cout << "-1\n";
		else{
			int dist = 600000;
			for (i = 0; i < ans.size(); i++){
				int s = ans[i],d=0;
				for (j = 1; j <= m; j++){
					if(j!=s)d = max(d, g[s][j]);
				}
				dist = min(d, dist);
			}
			cout << dist << "\n";
		}
	}
	return 0;
}
