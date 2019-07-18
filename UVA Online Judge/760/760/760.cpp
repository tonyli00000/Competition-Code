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

string x, y;
int c[400][400];
int LCSLength(int m, int n) {
	int i, j;
	//int c[400][400];
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
	bool first = true;
	while (true) {
		string tmp;
		if (!first)if(!getline(cin, tmp))break;
		if (!first)cout << "\n";
		first = false;

		if (!getline(cin, x))break;
		else {
			getline(cin, y);
		}
		int m=x.length(), n=y.length();
		int p=LCSLength(m, n);
		int i = m, j = n,index=c[m-1][n-1];

		char lcs[400];
		while (i > 0 && j > 0)
		{
			if (x[i - 1] == y[j - 1])
			{
				lcs[index - 1] = x[i - 1]; 
				i--; j--; index--;  
			}
			else if (c[i - 1][j] > c[i][j - 1])
				i--;
			else
				j--;
		}
		for (int i = 0; i < p;i++)
			cout << lcs[i];
		cout << "\n";
	}
    return 0;
}

