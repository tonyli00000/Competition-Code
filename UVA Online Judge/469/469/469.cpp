#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string y[100];
int matrix[100][100],column,row,len;
string temp;
int xx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int yy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int floodFill(int x, int z){
		int i,total=1;
		y[x][z] = 'X';
		for (i = 0; i < 8; i++){
			if ((y[x + xx[i]][z + yy[i]] == 'W') && (x + xx[i] >= 0) && (z + yy[i] >= 0) && (x + xx[i] < column) && (z + yy[i] < row)){
				total = total + floodFill(x, z);
				floodFill(x + xx[i], z + yy[i]);
			}
		}
		return total;
}
int main()
{
	int index, m, n, x, z, k, i, j, t, total;
	cin >> t;
	k = 0;
	bool flag = true;
	getline(cin, temp);
	getline(cin, temp);
	while ((t--)&&(t>0)){
		index = 0;
		total = 0;
		if (flag == false){
			cout << "\n";
			flag = false;
		}
		while ((getline(cin, temp))){
			if (temp.length() == 0)break;
			if ('A' <= temp[0] && temp[0] <= 'Z'){
				y[index] = temp;
				index++;
				continue;
			}
			column = y[0].length();
			row = index;
			len = temp.length();
			int space;
			for (i = 0; i < len; i++){
				if (temp[i] == ' '){
					space = i;
					break;
				}
			}
			if (space > 1){
				x = (int(temp[0]) - '0') * 10 + int(temp[1]) - '0';
			}
			else x = int(temp[0]) - '0';
			if (len - space-1 > 1)z = (int(temp[space + 1]) - '0') * 10 + int(temp[space + 2]) - '0';
			else z = int(temp[space + 1])-'0';
			if (y[x-1][z-1] == 'W'){
				total=floodFill(x - 1, z - 1);
			}
			else{
				total = 0;
			}
			cout << total << "\n";
			for (i = 0; i < column; i++){
				for (j = 0; j < row; j++){
					if (y[i][j] == 'X')y[i][j] = 'W';
				}
			}
		}
	}
	return 0;
}
