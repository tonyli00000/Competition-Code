#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int matrix[9][9];
int m[9][9];
int black = 0, white = 0;
int xx[] = { 0, -1, 0, 1 };
int yy[] = { -1, 0, 1, 0 };

void floodFill(int x, int y, int z){
	int i;
	if (z == 1)matrix[x][y] = -1;
	else matrix[x][y] = -2;
	for (i = 0; i < 4; i++){
		if (z == 1){
			if ((matrix[x + xx[i]][y + yy[i]] == 0) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))floodFill(x + xx[i], y + yy[i], z);
		}
		if (z == 2){
			if ((matrix[x + xx[i]][y + yy[i]] == 0) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))floodFill(x + xx[i], y + yy[i], z);
			if ((m[x + xx[i]][y + yy[i]] == 0) && (matrix[x + xx[i]][y + yy[i]] == -1) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))floodFill(x + xx[i], y + yy[i], z);
		}
	}
}
int main()
{
	int i, j, k, t, black2,white2;
	char c;
	cin >> t;
	for (k = 0; k < t; k++){
		black = 0;
		black2 = 0;
		white = 0;
		white2 = 0;
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				cin >> c;
				if (c == 'X'){
					matrix[i][j] = 1;
				}
				if (c == 'O'){
					matrix[i][j] = 2;
					//white++;
				}
				if (c == '.')matrix[i][j] = 0;
				m[i][j] = matrix[i][j];
			}
		}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				if (matrix[i][j] == 1)floodFill(i, j, 1);
			}
		}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				if (matrix[i][j] == -1)black2++;
			}
		}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				if (matrix[i][j] == 2)floodFill(i, j, 2);
			}
		}

		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				if (matrix[i][j] == 1 || matrix[i][j] == -1)black++;
				if (matrix[i][j] == 2 || matrix[i][j] == -2)white++;
			}
		}
		white = white - (black2 - black);
		cout << "Black "<<black << " White "<< white << "\n";
	}
	return 0;
}