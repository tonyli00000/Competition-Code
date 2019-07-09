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

bool connected[102][102];
int dist[102][102];

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
void find(int n) {
	int i, j, k;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (max(dist[i][k], dist[k][j]) < dist[i][j] && connected[i][k] && connected[k][j]) {
					dist[i][j] = max(dist[i][k], dist[k][j]);
					connected[i][j] = true;
				}
			}
		}
	}
}
int main()
{
	int a, b, c,i,j,k,t=0;
	while (cin >> a >> b >> c) {
		if (t != 0)cout << "\n";
		cout << "Case #" << ++t << "\n";
		if (a == 0 && b == 0 && c == 0)break;
		for (i = 0; i <= a; i++) {
			for (j = 0; j <= a; j++) {
				connected[i][j] = false;
				dist[i][j] = 30000;
			}
		}
		for (i = 0; i < b; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			connected[x][y] = true;
			connected[y][x] = true;
			dist[x][y] = z;
			dist[y][x] = z;
		}
		find(a);
		for (i = 0; i < c; i++) {
			int x, y;
			cin >> x >> y;
			if (dist[x][y] == 30000)cout << "no path\n";
			else cout << dist[x][y] << "\n";
		}
	}
	return 0;
}
