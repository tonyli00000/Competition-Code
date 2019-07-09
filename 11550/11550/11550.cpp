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

int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, n,mat[10][40];
		cin >> m >> n;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				cin >> mat[i][j];
		bool flag = false,connected[10][10];
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10;j++)
				connected[i][j] = false;
		for (i = 0; i < n; i++) {
			int ct = 0,a[2];
			for (j = 0; j < m; j++) {
				if (mat[j][i] == 1) {
					if (ct == 2)flag = true;
					else {
						a[ct] = j;
						ct++;
					}
				}
			}
			if (ct != 2)flag = true;
			if (flag)break;
			else {
				if (connected[a[0]][a[1]]) {
					flag = true;
					break;
				}
				else {
					connected[a[0]][a[1]] = true;
				}
			}
		}
		if (flag)cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
