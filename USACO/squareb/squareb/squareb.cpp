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
#pragma warning(disable:4996)
using namespace std;

int main()
{
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	int x = min(a, e), y = min(b, f), z = max(c, g), w = max(d, h);
	int ans = max(z - x, w - y);
	cout << ans*ans << "\n";
	return 0;
}

