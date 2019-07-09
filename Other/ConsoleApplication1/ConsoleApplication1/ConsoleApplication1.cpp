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
#include <numeric>
using namespace std;

using namespace std;
int a[2000 + 10][2000 + 10];
int main()
{
	int x1, x2, y1, y2, maxx = 0, minx = 2005, maxy = 0, miny = 2005, ans = 0;
	for (int i = 1; i <= 2; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 1001; x2 += 1001; y1 += 1001; y2 += 1001;
		if (x1>x2)swap(x1, x2);
		if (y1>y2)swap(y1, y2);
		for (int j = x1; j<x2; j++) {
			for (int k = y1; k<y2; k++) {
				a[j][k]++;
			}
		}
		if (x1<minx)minx = x1;
		if (x2>maxx)maxx = x2;
		if (y1<miny)miny = y1;
		if (y2>maxy)maxy = y2;
	}
	cin >> x1 >> y1 >> x2 >> y2;
	x1 += 1001; x2 += 1001;y1 += 1001;y2 += 1001;
	if (x1>x2)swap(x1, x2);
	if (y1>y2)swap(y1, y2);
	for (int j = x1; j<x2; j++) {
		for (int k = y1; k<y2; k++) {
			a[j][k] = 0;
		}
	}
	for (int i = minx; i<maxx; i++) {
		for (int j = miny; j<maxy; j++) {
			if (a[i][j] % 2)ans++;
		}
	}
	cout << ans<<"\n";
	return 0;
}




