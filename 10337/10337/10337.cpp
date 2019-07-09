#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;

long minn(long x, long y, long z) {
	if (x <= y && x <= z)return x;
	else {
		if (y <= x && y <= z)return y;
		else return z;
	}
}
int main()
{
	int t;
	cin >> t;
	long i, j, k;
	for (k = 0; k < t; k++) {
		long n;
		cin >> n;
		n /= 100;
		long fuel[10005][10];// alt[100005][3];
		for (i = 0; i <= n; i++) {
			for (j = 0; j < 10; j++) {
				fuel[i][j] = 700000;
				//alt[i][j] = 0;
			}
		}
		int wind[10][10005];
		for (i = 9; i >=0; i--) {
			for (j = 0; j < n; j++) {
				int x;
				cin >> x;
				wind[j][i] = x;
			}
		}
		//int act[3] = { 60,30,20 }, a[3] = { 1,0,-1 };
		fuel[0][0] = 0;
		for (i = 1; i <= n; i++) {
			for (j = 0; j <= 9; j++) {
				long a[3] = { 700000,700000,700000 };
				if (j - 1 >= 0)a[0] = fuel[i - 1][j - 1]+60-wind[(i-1)][j-1];
				if (j + 1 <10)a[2] = fuel[i - 1][j + 1]+20- wind[i - 1][j + 1];
				a[1] = fuel[i-1][j]- wind[i-1][j]+30;
				long q=minn(a[0], a[1], a[2]);
				fuel[i][j] = q;
			}
		}
		cout << fuel[n][0] << "\n";
		cout << "\n";
	}
	return 0;
}
