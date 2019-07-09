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

int color[102][102];
char mat[102][102];
int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 },n;
void floodfill(int x, int y,int id) {
	color[x][y] = id;
	int i;
	for (i = 0; i < 4; i++) {
		if (x + xx[i] < n && y + yy[i] < n && (mat[x + xx[i]][y + yy[i]] == '@' || mat[x + xx[i]][y + yy[i]] == 'x') && color[x + xx[i]][y + yy[i]] == -1)
			floodfill(x + xx[i], y + yy[i], id);
	}
}
int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> n;
		char c;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				color[i][j] = -1;
			}
		}
		int id = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (color[i][j] == -1 && mat[i][j] == 'x') {
					floodfill(i, j, id);
					id++;
				}
			}
		}
		cout << "Case " << k + 1 << ": " << id << "\n";
	}
	return 0;
}
