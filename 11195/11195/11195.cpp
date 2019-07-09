#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define N 15
using namespace std;
int x, y, z, b, n, i, j, k, p[15][15];
char m;
void solve(int step, int ans[N]){
	int i, j, k, row;
	for (i = 0; i < z; i++){
		ans[step] = i;
		for (row = 0; row < step; row++){
			if ((ans[row] == ans[step]) || (ans[row] + step - row == ans[step]) || (ans[row] - step + row == ans[step])||(p[step][row]==1))break;
		}
		if (row == step)solve(step + 1, ans);
	}
	if (step == z){
		b++;
	}
}
int main()
{
	int solution[15];
	while ((cin >> z)&&(z!=0)){
		for (i = 0; i < 15; i++){
			for(j=0;j<15;j++)p[i][j] = 0;
		}
		b = 0;
		for (i = 0; i < z; i++){
			for (j = 0; j < z; j++){
				cin >> m;
				if (m == '*')p[i][j] = 1;
			}
		}
		solve(0, solution);
		cout << "Case "<<k+1<<": "<<b << "\n";
		k++;
	}
	
	return 0;
}
