/*
ID:tonyli21
PROG:milk4
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
#pragma warning(disable:4996)

using namespace std;
int a[105], f[22005], g[22005], p[22005];
int i, j, k, n, m;
void dfs(int i, int j){
	if (i >= f[m]){
		for (i = 0; i<f[m]; i++){
			if (p[i]<a[i])break;
			if (p[i]>a[i])return;
		}
		for (i = 0; i<f[m]; i++)
			a[i] = p[i];
		return;
	}
	p[i] = g[j];
	for (int s = j; (j = j - g[s]) >= 0;){
		if (f[j] + 1 == f[s])dfs(i + 1, j);
	}
}
int main()
{
	freopen("milk4.in", "r", stdin);
	freopen("milk4.out", "w", stdout);
	while (cin>>m>>n){
		for (i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (i = 0; i <= m; i++){
			f[i] = n + 1;
			p[i] = 0;
		}
		f[0] = 0;
		for (i = n - 1; i >= 0; i--){
			for (j = m; j >= 0; j--){
				for (k = j + a[i]; k <= m; k += a[i]){
					if (f[k]>f[j] + 1 || (f[k] == f[j] + 1 && g[k] > a[i])){
						f[k] = f[j] + 1;
						g[k] = a[i];
					}
				}
			}
		}
		a[0] = m;
		dfs(0, m);
		cout << f[m];
		for (i = 0; i < f[m]; i++){
			cout << " " << g[a[i]];
		}
		cout << "\n";
	}
	return 0;
}