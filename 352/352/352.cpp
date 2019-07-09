#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int xx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, m, n;
int yy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool visited[102][102];
int matrix[102][102];
#define WAYS 8
bool flag = true;

// #define WAYS 4
// int xx[4] = { 1, 0, 0, -1 };
// int yy[4] = { 0, 1, -1, 0 };


void search(int x, int y, int eid)
{
	int i;

	matrix[x][y] = eid;
	for (i = 0; i < WAYS; i++)
		if ((matrix[x + xx[i]][y + yy[i]] == 0) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i]<m) && (y + yy[i]<n))
			search(x + xx[i], y + yy[i], eid);
}





//int floodfill(int x, int y,int eid){
//	
//	for (i=0; i < m; i++){
//		for (j=0; j < n; j++){
//			if (matrix[i][j] == 0){
//				if (flag == true){
//					eid++;
//					flag = false;
//				}
//				matrix[i][j] = eid;
//				for (k = 0; k < 8; k++){
//					if (matrix[x + xx[k]][y + yy[k]] == 0){
//						floodfill(x + xx[i], y + yy[i], eid);
//					}
//				}
//				if (k == 8)flag = true;
//			}
//			else floodfill(x, y,eid);
//		}
//	}
//	return eid;
//}
int main()
{
	int i, j, k, counter,t=1;
	char c;
	while ((cin >> m)){
		cout << "Image number " << t << " contains ";
		n = m;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				cin >> c;
				if (c == '0')matrix[i][j] = -1;
				else matrix[i][j] = 0;
			}
		}
		counter = 0;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				if (matrix[i][j] == 0){
					if (flag == true){
						counter++;
						flag = false;
					}
					search(i, j, counter);
					flag = true;
				}
			}
		}
		cout << counter << " war eagles.\n";
		t++;
	}
	return 0;
}
