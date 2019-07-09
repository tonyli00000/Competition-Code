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
int mat[107][107],id,m,n;
vector<int> ob;
int xx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int yy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void floodfill(int x, int y,int id) {
	mat[x][y] = id;
	ob[id - 1]++;
	int i;
	for (i = 0; i < 8; i++) {
		if (mat[x + xx[i]][y + yy[i]] == -1) {
			if (x + xx[i] < m && y + yy[i] < n && x + xx[i] >= 0 && y + yy[i] >= 0)floodfill(x + xx[i], y + yy[i], id);
		}
	}
}
int main()
{
	int i,j,k;
	while (cin >> m >> n) {
		if (!m && !n)break;
		id = 1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				char x;
				cin >> x;
				if (x == '*')mat[i][j] = -1;
				else mat[i][j] = 0;
			}
		}
		ob.clear();
		ob.resize(10005,0);
		int ct = 0;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (mat[i][j] == -1) {
					id++;
					floodfill(i, j, id);
					if (ob[id - 1] == 1)ct++;
				}
			}
		}
		cout << ct << "\n";
	}
	return 0;
}
