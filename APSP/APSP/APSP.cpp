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
					nex[i][j] = nex[i][k];
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
	return 0;
}
