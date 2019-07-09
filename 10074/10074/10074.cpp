#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;



int a[105][105];
int n;

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int i, j, k, b,m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)break;
		//long m = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 0)a[i][j] = 1;
				else a[i][j] = -1e5;
				if (i > 0)a[i][j] += a[i - 1][j];
				if (j > 0)a[i][j] += a[i][j - 1];
				if (i > 0 && j > 0)a[i][j] -= a[i - 1][j - 1];

			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = i; k < n; k++) {
					for (int l = j; l < m; l++) {
						int cur = a[k][l];
						if (i > 0) cur -= a[i - 1][l];
						if (j > 0) cur -= a[k][j - 1];
						if (i > 0 && j > 0) cur += a[i - 1][j - 1];
						ans = max(ans, cur);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}