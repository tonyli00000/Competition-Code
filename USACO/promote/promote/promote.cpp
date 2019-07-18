/*
ID: tonyli21
PROG: promote
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
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	long a, b, c, d, e, f,g,h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	int gtp = h - g;
	int stg = f - e + gtp;
	int bts = d - c + f - e + gtp;
	cout << bts << "\n";
	cout << stg << "\n";
	cout << gtp << "\n";
    return 0;
}

