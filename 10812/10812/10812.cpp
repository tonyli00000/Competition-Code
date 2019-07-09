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

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		long long a, b;
		cin >> a >> b;
		long long y = (a - b) * 10 / 2;
		long long x = a * 10 - y;
		if (x % 10 == 5)cout << "impossible\n";
		else {
			if (x < 0 || y < 0)cout << "impossible";
			else cout << x / 10 << " " << y / 10 << "\n";
		}
	}
	return 0;
}
