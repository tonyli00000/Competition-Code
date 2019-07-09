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
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int a, b, c, d,x,y,z,n;
	cin >> a >> b >> c >> d;
	int ct = 0;
	for (int i = 0; i < 100; i++) {
		if (i >= a && i + 1 <= b) {
			ct++;
		}
		else if (i >= c && i + 1 <= d) {
			ct++;
		}
	}
	cout << ct << "\n";
	//if (b < c)cout << a - b + d - c << "\n";
	//else {
	//	x = min(a, c);
	//	y = max(b, d);
	//	cout << y - x << "\n";
	//}
	return 0;
}
