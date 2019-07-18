#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string grid[60],temp;
int xx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int yy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int number[1000];
int h, w;
void floodfill(int x, int y, int id){
	int i;
	if (grid[x][y] == 'X')grid[x][y] = 'x';
	else grid[x][y] = char(int('A' + id));
	for (i = 0; i < 8; i++){
		if ((grid[x + xx[i]][y + yy[i]] == '*' || grid[x + xx[i]][y + yy[i]] == 'X') && (x + xx[i] >= 0) && (x + xx[i] < h) && (y + yy[i] >= 0) && (y + yy[i] < w))floodfill(x, y, id);
	}
}
void floodfill2(int x, int y, int id){
	int i, j, k;
	grid[x][y] = '.';
	for (i = 0; i < 8; i++){
		if ((grid[x + xx[i]][y + yy[i]] == 'x') && (x + xx[i] >= 0) && (x + xx[i] < h) && (y + yy[i] >= 0) && (y + yy[i] < w))floodfill2(x, y, id);
	}
}

int main()
{
	int i, j, k,l2,w2,t=0,id;
	
	while((cin>>h>>w)&&(h!=0)&&(w!=0)){
		getline(cin, temp);
		id = 0;
		for (i = 0; i < h; i++){
			getline(cin, grid[i]);
		}
		int b = 0,l;
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				if (grid[i][j] == '*'){
					floodfill(i, j, id);
					for (k = 0; k < h; k++){
						for (l = 0; l < w; l++){
							int count = 0;
							if (grid[k][l] == 'x'){
								floodfill2(k, l, id);
								number[b]++;
							}
						}
						id++;
						b++;
					}
				}
			}
		}
			int c = 0;
			cout << "Throw " << t << "\n";
			while (number[c] != 0){
				cout << number[c] << " ";
				c++;
			}
			t++;
	}
	return 0;
}
