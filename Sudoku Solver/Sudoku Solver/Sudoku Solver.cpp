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

int mat[9][9];
bool p[9][9][9];
void fill(int x, int y, int n) {
	int i, j, k;
	for (i = 0; i < 9; i++) {
		p[i][y][n] = true;
	}
	for (i = 0; i < 9; i++) {
		p[x][i][n] = true;
	}
	int a = x / 3 , b = y / 3 ;
	for (i = a * 3; i < a * 3 + 3; i++) {
		for (j = b * 3; j < b * 3 + 3; j++) {
			p[i][j][n] = true;
		}
	}
}
bool checkgrid() {
	int i, j, k;
	bool q=true;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			int ct = 0,a=-1;
			if (mat[i][j] == -1)q = false;
			for (k = 0; k < 9; k++) {
				if (!p[i][j][k]) {
					ct++;
					a = k;
					if (ct > 1)break;
				}
			}
			if (k == 9 && mat[i][j]==-1) {
				mat[i][j] = a;
				fill(i, j, a);
			}
		}
	}
	return q;
}
int main()
{
	int i, j, k;
	while (true) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				for (k = 0; k < 9; k++) {
					p[i][j][k] = false;
				}
			}
		}
		for (i = 0; i < 9; i++) {
			string line;
			getline(cin, line);
			for (j = 0; j < 9; j++) {
				char x;
				x = line[j];
				if (x == '0')mat[i][j] = -1;
				else {
					mat[i][j] = x - '0';
					fill(i, j, mat[i][j]);
				}
			}
		}
		while (!checkgrid()) {
			for (i = 0; i < 9; i++) {
				for (j = 0; j < 9; j++) {
					if (mat[i][j] != -1)fill(i, j, mat[i][j]);
				}
			}
		}
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cout << mat[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}



