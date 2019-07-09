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
	int t,i,j,k;
	cin >> t;
	while (t--){
		int x, y;
		cin >> x >> y;
		vector<vector<pair<long long, long long>>>dist(x + 1, vector<pair<long long, long long>>(x + 1, { 10000000, 10000000 }));
		for (i = 0; i < y; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			dist[a][b] = { c, d };
			dist[b][a] = { c, d };
		}
		for (i = 1; i <= x; i++){
			dist[i][i] = { 0, 0 };
		}
		for (k = 1; k <= x; k++){
			for (i = 1; i <= x; i++){
				for (j = 1; j <= x; j++){
					pair<long long, long long>a = { dist[i][k].first + dist[k][j].first, dist[i][k].second + dist[k][j].second };
					if (a.first == dist[i][j].first && a.second < dist[i][j].second){
						dist[i][j] = a;
						continue;
					}
					if (a.first < dist[i][j].first){
						dist[i][j] = a;
					}
				}
			}
		}
		int q;
		cin >> q;
		while (q--){
			int a, b;
			cin >> a >> b;
			if (dist[a][b].first == 10000000)cout << "No Path.\n";
			else cout << "Distance and time to reach destination is " << dist[a][b].second << " & " << dist[a][b].first << ".\n";
		}
		if (t)cout << "\n";
	}
	return 0;
}
