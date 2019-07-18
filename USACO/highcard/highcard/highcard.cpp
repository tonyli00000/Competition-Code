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
	map<long, bool> e;
	vector<long>a, b;
	long n,i,j,k;
	cin >> n;
	for (i = 0; i < n; i++) {
		long x;
		cin >> x;
		e[x] = false;
	}
	for (i = 1; i <= 2 * n; i++) {
		if (e.find(i) == e.end())b.push_back(i);
		else a.push_back(i);
	}
	int ans = 0;
	int x = 0;
	int y = 0;
	while (x < n && y < n) {
		if (b[x] > a[y]) {
			ans++;
			x++;
			y++;
		}
		else {
			x++;
		}
	}
	cout << ans << "\n";
	return 0;
}
