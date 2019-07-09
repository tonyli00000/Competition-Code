#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int grid[20][20], n, xx[2] = { 1,0 }, yy[2] = { 0,1 },solution[100],con=0;
string ans[50000];
void find(int step,int x, int y) {
	int i, j, k;
	if (step == 2*n-2) {
		string temp = "";
		for (k = 0; k <= step; k++)temp += char(solution[k] + 'A');
		
		for (k = 0; k < con; k++)if (ans[k] == temp)break;
		if (k == con) {
			ans[con] = temp;
			con++;
		}
		return;
	}
	if (step > n-1+((n-1)%2)) {
		for (i = step-1; i > n-1; i--) {
			if (solution[i] != solution [n - (i - (n - 1)) - 1]) {
				return;
			}
		}
	}
	for (i = 0; i < 2; i++) {
			if (x + xx[i] < n && y + yy[i] < n && y+yy[i]>=0) {
				solution[step]= grid[x + xx[i]][y + yy[i]];
				find(step+1, x + xx[i], y + yy[i]);
			}
		
	}
	
}
int main()
{
	int i,j,k;
	while (cin >> n && n != 0) {
		for (i = 0; i < 20; i++) {
			for (j = 0; j < 20; j++)grid[i][j] = 0;
		}
		con = 0;
		for (i = 0; i < 50000; i++)ans[i] = "";
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++){
				char c;
				cin >> c;
				grid[i][j] = c - 'A';
			}
		}
		int count = 0;
		solution[0] = grid[0][0];
		for (i = 0; i < 100; i++)solution[i] = 0;
		find(1, 0, 0);
		cout << con << "\n";
	}
	return 0;
}
