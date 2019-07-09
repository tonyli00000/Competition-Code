#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k,x[10000],y[10000],xx[10000],yy[10000];
double slope[10000], ict[10000];

int solve(int x, int y) {
	int i, j, k;
	int a, b;
	if (slope[x] == -30000)return ict[x];
	else if (slope[y] = -30000)return ict[y];
	else {
		a = slope[x] - slope[y];
		b = ict[y] - ict[x];
		return b / a;
	}
}
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int min(int x, int y) {
	if (x > y)return y;
	else return x;
}
int main()
{
	int t;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m,x1,y1,x2,y2,l=0;
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			x[i] = x1;
			y[i] = y1;
			xx[i] = x2;
			yy[i] = y2;
			if (x1 == x2) {
				slope[i] = -30000;
				ict[i] = x1;
			}
			else {
				slope[i] = (y2 - y1)*1.0 / (x2 - x1)*1.0;
				ict[i] = y1 - slope[i] * 1.0*x1;
			}
		}
		int con = 0;
		for (i = 0; i < m; i++) {
			for (j = 0; j < m;j++){
				int a = 0;
				if (i != j) {
					if (slope[i] != slope[j]) {
						a = solve(i, j);
						if (slope[i] == -30000 || slope[j] == -30000) {
							int b = 0;
							if (slope[i] == -30000)b = ict[j];
							else b = ict[i];
							if (max(slope[j], slope[i])*a*1.0+b>0)con++;
						}
						else {
							a = solve(i, j);
							if (a < 0 || a*slope[i] * 1.0 + ict[i] < 0);
							else con++;
						}
					}
				}
				//if (min(x[i], xx[i]) < a && max(x[i], xx[i]) > a && min(x[j], xx[j]) < a && max(x[j], xx[j]) > a && min(y[i], yy[i]) < a && max(y[j], yy[j]) > a && min(y[j], yy[j]) < a && max(y[j], yy[j]) > a)con++;
			}
		}
		cout << con / 2<<"\n";
	}
	return 0;
}
