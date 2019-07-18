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

using namespace std;

bool connected[2002][2002];
int dist[2002][2002];

void find(int n) {
	int i, j, k;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (connected[i][k] && connected[k][j] && dist[i][j]>dist[i][k]+dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					connected[i][j] = true;
				}
			}
		}
	}
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n) {
		if (n == 0 && m == 0)break;
		for (i = 0; i <= m; i++) {
			for (j = 0; j <= m; j++) {
				connected[i][j] = false;
				dist[i][j] = 50000;
			}
		}
		for (i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			connected[a][b] = true;
			dist[a][b] = 1;
			if (c == 2) {
				connected[b][a] = true;
				dist[b][a] = 1;
			}
		}
		for (i = 1; i <= m; i++) {
			dist[i][i] = 0;
		}
		find(m);
		bool flag = true;
		for (i = 1; i <= m; i++) {
			if (!flag)break;
			for (j = i + 1; j <= m; j++) {
				if (dist[i][j] == 50000 || dist[j][i] == 50000) {
					flag = false;
					break;
				}
			}
			if (!flag)break;
		}
		if (flag)cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
