/*
ID: tonyli21
PROG: angry
LANG: C++11
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

using namespace std;


int main()
{
	//freopen("paint.in", "r", stdin);
	//freopen("paint.out", "w", stdout);
	long long n, q,i,j,k;
	cin >> n >> q;
	vector<vector<long long>>p;
	p.resize(n + 2);
	p[0].resize(3);
	p[0][0] = 0;
	p[0][1] = 0;
	p[0][2] = 0;
	for (i = 1; i <= n; i++) {
		p[i].resize(3);
		for (j = 0; j < 3; j++) {
			p[i][j] = p[i - 1][j];
		}
		int x;
		cin >> x;
		p[i][x - 1]++;
	}
	for (i = 0; i < q; i++) {
		long long a, b;
		cin >> a >> b;
		cout << p[b][0] - p[a-1][0] << " " << p[b][1] - p[a-1][1] << " " << p[b][2] - p[a-1][2] << "\n";
	}
	return 0;
}
