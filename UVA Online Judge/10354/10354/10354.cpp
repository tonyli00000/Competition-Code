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
#include<bitset>
#define INF 999999
using namespace std;

int main()
{
	int a, b, c, d, e, f,i,j,k;
	while (cin >> a >> b >> c >> d >> e >> f) {
		c--;
		d--;
		e--;
		f--;
		int dist[105][105],next[105][105],dist_2[105][105];
		for (i = 0; i <= a; i++) {
			for (j = 0; j <= a; j++) {
				dist[i][j] = INF;
				dist[j][j] = 0;
				dist_2[j][j] = 0;
				dist_2[i][j] = INF;
				next[i][j] = -1;
			}
		}
		for (i = 0; i < b; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			x--, y--;
			dist[x][y] = z, dist[y][x] = z;
			dist_2[x][y] = z, dist[y][x] = z;
			next[x][y] = y, next[y][x] = x;
		}
		for (k = 0; k < a; k++) {
			for (i = 0; i < a; i++) {
				for (j = 0; j < a; j++) {
					if (dist[i][j]>dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
				}
			}
		}
		bitset < 101 > cant;
		cant.reset();
		for (int inter = 0; inter < a; inter++)
			if (dist[c][d] == dist[c][inter] + dist[inter][d]) {
				cant.set(inter);
				dist_2[inter][inter] = INF;
			}
		for (k = 0; k < a; k++) {
			if (cant.test(k))continue;
			for (i = 0; i < a; i++) {
				if (cant.test(i))continue;
				for (j = 0; j < a; j++) {
					if (cant.test(j))continue;
					if (dist_2[i][j]>dist_2[i][k] + dist_2[k][j]) {
						dist_2[i][j] = dist_2[i][k] + dist_2[k][j];
					}
				}
			}
		}
		if (dist_2[e][f] == INF || cant.test(e) || cant.test(f))cout << "MISSION IMPOSSIBLE.\n";
		else cout << dist_2[e][f] << "\n";
	}
	return 0;
}
