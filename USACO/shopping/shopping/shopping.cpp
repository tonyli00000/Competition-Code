/*
ID:tonyli21
PROG:shopping
LANG:C++11
*/
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
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;

int f[6][6][6][6][6], s, b, n, p[100][1000], a[6] = { 0 }, b1[6], pr[10];
int main(){
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	int c, k, pi, a1, a2, a3, a4, a5;
	cin >> s;
	for (int i = 1; i <= s; i++){
		cin >> n;
		for (int j = 1; j <= n; ++j){
			cin >> c >> k;
			p[i][c] = k;
		}
		cin >> pi;
		p[i][999] = pi;
	}
	cin >> b;
	for (int i = 1; i <= b; ++i){
		cin >> c >> k >> pi;
		a[i] = k;
		b1[i] = c;
		pr[i] = pi;
	}
	f[0][0][0][0][0] = 0;
	for (int i = 0; i <= a[1]; i++)
		for (int j = 0; j <= a[2]; j++)
			for (int k = 0; k <= a[3]; k++)
				for (int l = 0; l <= a[4]; l++)
					for (int m = 0; m <= a[5]; m++)
					{
						f[i][j][k][l][m] = pr[1] * i + pr[2] * j + pr[3] * k + pr[4] * l + pr[5] * m;
						for (int n = 1; n <= s; ++n){
	
							a1 = i - p[n][b1[1]];
							a2 = j - p[n][b1[2]];
							a3 = k - p[n][b1[3]];
							a4 = l - p[n][b1[4]];
							a5 = m - p[n][b1[5]];
							if (a1 < 0 || a2 < 0 || a3 < 0 || a4 < 0 || a5 < 0)
								continue;
							else
							{
								int now = f[a1][a2][a3][a4][a5] + p[n][999];
								if (now < f[i][j][k][l][m])
									f[i][j][k][l][m] = now;
							}
						}
					}
	cout<<f[a[1]][a[2]][a[3]][a[4]][a[5]]<<"\n";
	return 0;
}