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
	int n;
	while (cin >> n) {
		int a, b, c, d, e, ct = 0;
		cin >> a >> b >> c >> d >> e;
		if (a == n)ct++;
		if (b == n)ct++;
		if (c == n)ct++;
		if (d == n)ct++;
		if (e == n)ct++;
		cout << ct << "\n";
	}
	return 0;
}
