#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int matrix[9][9];
int black = 0, white = 0;
int xx[4] = { 0, -1, 0, 1 };
int yy[4] = { -1, 0, 1, 0 };

int neighbors(int x, int y){
	int i,color=0,b=0;
	for (i = 0; i < 4; i++){
		//if ((matrix[x + xx[i]][y + yy[i]] == 0) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))return -1;
		if ((matrix[x + xx[i]][y + yy[i]] != 0)&&(matrix[x+xx[i]][y+yy[i]]!=-1) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9)){
			color = matrix[x + xx[i]][y + yy[i]];
			break;
		}
	}
	if (color != 0){
		for (i = 0; i < 4; i++){
			//if ((matrix[x + xx[i]][y + yy[i]] == 0) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))return -1;
			if ((x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i] < 9) && (y + yy[i] < 9))if ((color != matrix[x + xx[i]][y + yy[i]])&&(matrix[x+xx[i]][y+yy[i]]!=0)&&(matrix[x+xx[i]][y+yy[i]]!=-1))return -1;
		}
		if (i == 4)return color;
	}
	else 
		
}
void floodFill(int x, int y, int z){
	if (x < 0 || x >= 9)return;
	if (y < 0 || y >= 9)return;
	if (matrix[x][y] != 0)return;
	if ((neighbors(x, y) == -1))return;
	if (neighbors(x, y) != z)return;
	matrix[x][y] = -1;
	if (z == 1)black++;
	else white++;
	int k;
	for (k = 0; k < 4; k++)floodFill(x + xx[k], y + yy[k], z);
}
int main()
{
	int i, j, k, t,color1;
	char c;
	cin >> t;
	for (k = 0; k < t; k++){
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++){
				cin >> c;
				if (c == 'X'){
					matrix[i][j] = 1;
					black++;
				}
				if (c == 'O'){
					matrix[i][j] = 2;
					white++;
				}
				if (c == '.')matrix[i][j] = 0;
			}
		for (i = 0; i < 9; i++){
			for (j = 0; j < 9; j++){
				if (neighbors(i, j)!=-1)floodFill(i, j, neighbors(i, j));

			}
		}
		cout << black << "\n";
		cout << white << "\n";
	}
	return 0;
}
