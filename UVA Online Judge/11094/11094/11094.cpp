#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int m, n,matrix[25][25],x,y,p=0;

int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };

int floodfill(int x, int y,int z,int p,int con) {
	int i;

	matrix[x][y] = p;
	for (i = 0; i < 4; i++) {
		if (matrix[x + xx[i]][y + yy[i]] == z && x + xx[i] >= 0 && x + xx[i] <= m - 1 && y + yy[i] >= 0 && y + yy[i] <= n - 1) {
			floodfill(x + xx[i], y + yy[i], z, p, con + 1);
		}
	}
	return con;
}
int main()
{
	int i, j, k;
	char c,a[2];
	while (cin >> m >> n) {
		a[0] = ' ';
		a[1] = ' ';
		for (i = 0; i < 25; i++) {
			for (j = 0; j < 25; j++)matrix[i][j] = 0;
		}
		bool flag = true;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cin >> c;
				if (c != a[0] && c != a[1] && flag) {
					a[0] = c;
					flag = false;
				}
				if (c != a[0] && c != a[1] && flag==false)a[1] = c;
				if (c == a[0])matrix[i][j] = 0;
				else matrix[i][j] = 1;
			}
		}
		cin >> x >> y;
		p = -1;
		int l = matrix[x][y];
		int q=floodfill(x, y,matrix[x][y],p,c);
		p--;
		int con = 0, c = 0;;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (matrix[i][j] == l) {
					c = 0;
					if(floodfill(i,j,l,p,1)>c)c=floodfill(i, j, l, p,1);
					p--;
				}
			}
		}
		cout << c << "\n";
	}
	return 0;
}
