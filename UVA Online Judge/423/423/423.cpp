#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int dist[102][102], i, j, k = 0;

void find(int n) {
	int i, j, k;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main()
{
	int n;
	while (cin >> n) {
		for (i = 0; i<n; i++)dist[i][i] = 0;
		for (i = 0; i<102; i++) {
			for (j = 0; j<102; j++)dist[i][j] = 30000;
		}
		for (i = 0; i<n - 1; i++) {
			for (j = 0; j<i + 1; j++) {
				cin >> dist[i + 1][j];
				dist[j][i + 1] = dist[i + 1][j];
				if (dist[i + 1][j] == 'x') {
					dist[i + 1][j] = 30000;
					dist[j][i + 1] = 30000;
				}
			}
		}
		find(n);
		k = 0;
		for (i = 1; i<n; i++) {
			if (dist[0][i]>k)k = dist[0][i];
		}
		cout << k << "\n";
	}
	return 0;
}
