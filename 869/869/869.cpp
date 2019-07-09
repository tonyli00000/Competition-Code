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
int i, j, k;
/***************************
Algorithm: All Pairs Shortest Path
Time Complexity:  O (n^3)
Space Complexity: n^2
***************************/


vector<vector<int>>nex;
/*Used in finding the actual path after shortest distance is computed
Initialization:
for each edge (u->v):
nex[u][v]=v
*/

vector<vector<int>>dist;
/*Used to find the shortest distance
Initialization:
for each edge (u->v):
dist[u][v]=weight;
If graph is undirected: dist[v][u]=weight
*/
void APSP(int n, vector<vector<int>>&dist){
	int i, j, k;
	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					//nex[i][j] = nex[i][j];
				}
			}
		}
	}
}
vector<int>printpath(int x, int y){
	vector<int>ret;
	while (x != y){
		ret.push_back(x);
		x = nex[x][y];
	}
	ret.push_back(y);
	return ret;
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<vector<int>>dist(26, vector<int>(26, 60000)), dist2(26, vector<int>(26, 60000));
		for (i = 0; i < 26; i++){
			dist[i][i] = 0;
			dist2[i][i] = 0;
		}
		for (i = 0; i < n; i++){
			char x, y;
			cin >> x >> y;
			dist[x - 'A'][y - 'A'] = 1;
			dist[y - 'A'][x - 'A'] = 1;
		}
		cin >> n;
		for (i = 0; i < n; i++){
			char x, y;
			cin >> x >> y;
			dist2[x - 'A'][y - 'A'] = 1;
			dist2[y - 'A'][x - 'A'] = 1;
		}
		APSP(26, dist);
		APSP(26, dist2);
		bool ret = true;
		for (i = 0; i < 26; i++){
			for (j = 0; j < 26; j++){
				if (dist[i][j] == 60000 && dist2[i][j] == 60000)continue;
				if (dist[i][j] != 60000 && dist2[i][j] != 60000)continue;
				ret = false;
			}
		}
		if (ret)cout << "YES\n";
		else cout << "NO\n";
		if (t)cout << "\n";
	}
	return 0;
}
