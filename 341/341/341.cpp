#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 35000
using namespace std;
int i, j, k,N,matrix[15][15],previous[15][15],street,intersections,x,y;
bool flag;

void findpath(int x, int y){
	if (previous[x][y] == -1){
		if (flag == true){
			flag = false;
			cout << x + 1 << " " << y + 1;
		}
		else cout << " " << y + 1;
	}
	else {
		findpath(x, previous[x][y]);
		findpath(previous[x][y],y);
	}
}
int main()
{
	int test = 1;
	while ((cin >> N) && (N != 0)){
		for (i = 0; i < 15; i++)
			for (j = 0; j < 15; j++)
			{
				matrix[i][j] = MAXN;
				previous[i][j] = -1;
			}
		for (i = 0; i < N; i++){
			cin >> street;
			for (j = 0; j < street; j++){
				cin >> intersections;
				cin >> y;
				matrix[i][intersections - 1] = y;
			}
		}
		cin >> x >> y;
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				for (k = 0; k < N; k++){
					if (matrix[j][k] > matrix[j][i] + matrix[i][k])
					{
						matrix[j][k] = matrix[j][i] + matrix[i][k];
						previous[j][k] = i;
					}
				}
			}
		}
		flag = true;
		cout << "Case " << test << ": Path = ";
		findpath(x - 1, y - 1);
		cout << "; " <<	matrix[x-1][y - 1] << " second delay\n";
		test++;
	}
	return 0;
}

