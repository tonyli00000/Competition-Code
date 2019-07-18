#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

long dist[10000][10000];

long long max(long long x, long long y) {
	if (x < y)return y;
	else return x;
}
void find(int t,int p) {
	int i, j, k;
	if (p == 0) {
		for (k = 0; k < t; k++) {
			for (i = 0; i < t; i++) {
				for (j = 0; j < t; j++) {
					if (dist[i][k] + dist[k][j] < dist[i][j])dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	else {
		for (k = 0; k < t; k++) {
			for (i = 0; i < t; i++) {
				for (j = 0; j < t; j++) {
					if (max(dist[i][k],dist[k][j]) < dist[i][j])dist[i][j] = max(dist[i][k],dist[k][j]);
				}
			}
		}
	}
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n && m != 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)dist[i][j] = 1000000;
		}
		for (i = 0; i < n; i++) {
			long long x, y,z;
			cin >> x >> y;
			cin >> z;
			if (dist[x][y]>z && dist[y][x]) {
				dist[x][y] = z;
				dist[y][x] = dist[x][y];
			}
		}
		find(m,0);
		find(m, 1);
		long long o = 0;
		bool flag = false;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][j]>o)o = dist[i][j];
			}
		}
		if (o == 0)cout << "IMPOSSIBLE\n";
		else cout << o << "\n";
	}
	return 0;
}
