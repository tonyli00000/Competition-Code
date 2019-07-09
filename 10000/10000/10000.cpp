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
	int t = 0,n,i,j,k;
	while (cin >> n &&n){
		int start;
		cin >> start;
		start--;
		int dist[105][105];
		for (i = 0; i <= n; i++){
			for (j = 0; j <= n; j++){
				dist[i][j] = -1;
			}
		}
		int x, y;
		while (cin >> x >> y){
			if (!x&&!y)break;
			dist[x - 1][y - 1] = 1;
		}
		for (k = 0; k < n; k++){
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					if (dist[i][k] > 0 && dist[k][j] > 0){
						if (dist[i][k] + dist[k][j] > dist[i][j])dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		int m = -1,dest;
		for (i = 0; i < n; i++){
			if (dist[start][i] > m){
				m = dist[start][i];
				dest = i;
			}
		}
		cout << "Case " << ++t << ": The longest path from " << ++start << " has length " << m << ", finishing at " << ++dest << ".\n\n";
	}
	return 0;
}
