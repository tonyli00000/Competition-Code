#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int m,n;
char matrix[100][100];

int xx[4] = { 0, -1, 0, 1 };
int yy[4] = { -1, 0, 1, 0 };

void floodFill(int x, int y, char z){
	if (x < 0 || x >= m)
		return;
	if (y < 0 || y >= n)
		return;
	if (matrix[x][y] != z)
		return;
	matrix[x][y] = '-';
	int k;
	for (k = 0; k < 4;k++)floodFill(x + xx[k], y + yy[k], z);
}

int main(){
	int t,i,j,p,l;
	cin >> t;
	for (int l = 1; l <= t; l++){
		cin >> m >> n;
		for (p = 0; p < m; p++){
			for (i = 0; i < n; i++)cin >> matrix[p][i];
		}
		int letters[30];
		for (i = 0; i < 26;i++)letters[i] = 0;
		for(i=0;i<m;i++){
			for (j = 0; j < n; j++){
				if (('a'<=(matrix[i][j]))&&(matrix[i][j]<='z')){
					letters[matrix[i][j] - 'a']++;
					floodFill(i, j, matrix[i][j]);
				}
			}
		}
		cout << "World #" << l << "\n";
		int index = 0;
		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				if (letters[index] < letters[j]){
					index = j;
				}
			}
			if (letters[index] > 0){
				cout << char('a' + index) << ": " << letters[index] << "\n";
				letters[index] = 0;
			}
		}
	}
	return 0;
}