#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };

string grid[55];
char c;
int die[100];
int m, n,q;
string temp3[55];
bool e = false;
void floodfill2(int x, int y, int z){
	int i;
	grid[x][y] = z+'0';
	for (i = 0; i < 4; i++){
		if ((x + xx[i] >= 0) && (x + xx[i] < n) && (y + yy[i] >= 0) && (y + yy[i] < m) && ((grid[x + xx[i]][y + yy[i]] == 'X')||(grid[x+xx[i]][y+yy[i]]=='0'))){
			floodfill2(x + xx[i], y+yy[i], z);
		}
	}

	return;
}
void floodfill(int x, int y,int id){
	int i;
	if (grid[x][y] == '*')grid[x][y] = char(id + '0');
	if (grid[x][y] == 'X')grid[x][y] = '0';
	for (i = 0; i < 4; i++){
		if ((x + xx[i] >= 0) && (x + xx[i] < n) && (y + yy[i] >= 0) && (y + yy[i] < m) && ((grid[x + xx[i]][y + yy[i]] == '*') || grid[x + xx[i]][y + yy[i]] == 'X')){
			floodfill(x + xx[i], y + yy[i], id);
		}
	}
	return;
}
void floodfill3(int x, int y){
	int i;
	if (temp3[x][y] == '*'){
		q = int(grid[x][y] - '0');
		temp3[x][y] = '/';
		grid[x][y] = '0';
		e = true;
	}
	else temp3[x][y] = 'x';
	for (i = 0; i < 4; i++){
		if ((x + xx[i] >= 0) && (x + xx[i] < n) && (y + yy[i] >= 0) && (y + yy[i] < m) && ((temp3[x + xx[i]][y + yy[i]] == '*') || temp3[x + xx[i]][y + yy[i]] == 'X')){
			floodfill3(x + xx[i], y + yy[i]);
		}
	}
	if (i == 4 && e==false)q = -1;
}
int main()
{
	int i, j, k, id, t = 0,l=0;
	string temp;
	while ((cin >> m >> n) && (m != 0) && (n != 0)){
		l++;
		t = 0;
		for (i = 0; i < 100; i++)die[i] = 0;
		id = 1;
		getline(cin, temp);
		for (i = 0; i < n; i++){
			getline(cin, grid[i]);
			temp3[i] = grid[i];
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				if (grid[i][j] == '*'){
					t++;
					floodfill(i, j,id);
					id++;
				}
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				if (grid[i][j] == '0'||grid[i][j]=='X'){
					if (j - 1 < 0){
						k = int(grid[i][j + 1] - '0');
						if (k == 40)k = 0;
					}
					else k = int(grid[i][j - 1] - '0');
					if (k+'0' == '.'){
						k = t + 1;
						t++;
					}
					
					if (k == 0){
						e = false;
						floodfill3(i, j);
						k = q;
						if (q == -1){
							k = t + 1;
							t++;
						}
					}
					die[k-1]++;
					floodfill2(i, j, k);
				}	
			}
		}
		for (i = 0; i < t; i++){
			for (j = i + 1; j < t; j++){
				if (die[j] < die[i]){
					int temp = 0;
					temp = die[i];
					die[i] = die[j];
					die[j] = temp;
				}
			}
		}
		cout << "Throw " << l << "\n";
		for (i = 0; i < t-1; i++)cout << die[i]<<" ";
		cout << die[t - 1] << "\n";
		cout << "\n";
	}
	return 0;
}
