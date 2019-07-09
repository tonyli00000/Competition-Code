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
vector<int> x;
vector<int> y;
int c[105][105];
int LCSLength(int m, int n) {
	int i, j;

	for (i = 0; i <= m; ++i)
		c[i][0] = 0;

	for (j = 0; j <= n; ++j)
		c[0][j] = 0;

	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[m][n];
}
int main()
{
	int m, n, i, j, k,t=0;
	while (cin >> m >> n) {
		if (!m &&!n)break;
		x.clear();
		y.clear();
		for (i = 0; i < m; i++) {
			int s;
			cin >> s;
			x.push_back(s);
		}
		for (i = 0; i < n; i++) {
			int s;
			cin >> s;
			y.push_back(s);
		}
		cout << "Twin Towers #" << ++t << "\n";
		cout << "Number of Tiles : " << LCSLength(m, n) << "\n";
		cout << "\n";
	}
	return 0;
}
