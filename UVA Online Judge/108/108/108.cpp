#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;



long a[105][105];
int n;

long max(long x, long y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int i, j, k, b;
	cin >> n;
	long m=0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> a[i][j];
				if (i > 0)a[i][j] += a[i - 1][j];
				if (j > 0)a[i][j] += a[i][j - 1];
				if (i > 0 && j > 0)a[i][j] -= a[i - 1][j - 1];

			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i; k < n; k++) {
					for (int l = j; l < n; l++) {
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

	return 0;
}