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

string x, y;
int c[1002][1002];
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
	int t = 0;
	while (getline(cin, x)) {
		getline(cin, y);
		int len = LCSLength(x.length(), y.length());
		cout << len << "\n";
	}
	return 0;
}