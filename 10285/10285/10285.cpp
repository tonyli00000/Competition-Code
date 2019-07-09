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
		string name;
		cin >> name;
		int m, n,dist[105][105],field[105][105];
		cin >> m >> n;
		for (i = 0; i <= m+1; i++){
			for (j = 0; j <= n+1; j++){
				dist[i][j] = -1;
				field[i][j] = -1;
			}
		}
		for (i = 1; i <= m; i++){
			for (j = 1; j <= n; j++){
				cin >> field[i][j];
				if (field[i - 1][j] != -1){
					if (field[i - 1][j] > field[i][j])dist[i*n-n-n+j][i*n-n+j] = 1;
					else dist[i*n + j][i*n - n + j] = 1;
				}
				if (field[i][j-1] != -1){
					if (field[i][j-1] > field[i][j])dist[i*n - n+j-1][i*n -n+ j] = 1;
					else dist[i*n-n+j][i*n-n+j-1] = 1;
				}
			}
		}
		int result = 0;
		for (k = 1; k <= m*n; k++){
			for (i = 1; i <= m*n; i++){
				for (j = 1; j <= m*n; j++){
					if (dist[i][k] != -1 && dist[k][j] != -1 && dist[i][k] + dist[k][j] > dist[i][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
					result = max(result, dist[i][j]);
				}
			}
		}
		cout << name << ": " << result << "\n";
	}
	return 0;
}
