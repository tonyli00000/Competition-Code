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

char mat[1005][1005];
int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int min_dist(int x, int y,int m)
{
	int k = 1000;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] == '3')
			{
				int tmp = abs(x - i) + abs(y - j);
				k = min(k, tmp);
			}
	return k;
}
int main()
{
	int m;
	while (cin >> m)
	{
		for (int i = 0; i<m; i++)
			for (int j = 0; j<m; j++)
				cin >> mat[i][j];

		int mx = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == '1') {
					int x = min_dist(i, j, m);
					mx = max(mx, x);
				}
			}
		}
		cout << mx << "\n";
	}
	return 0;
}
