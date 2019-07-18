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
	int t,tc=0;
	cin >> t;
	while (t--) {
		long long x[3], y, z;
		cin >> x[0] >> x[1] >>x[2];
		cout << "Case " << ++tc << ": ";
		if (x[0] == x[1] && x[1] == x[2])cout << "Equilateral\n";
		else {
			sort(x, x + 3);
			if (x[0] + x[1] <= x[2])cout << "Invalid\n";
			else {
				if (x[0] == x[1] || x[1] == x[2] || x[0] == x[2])cout << "Isosceles\n";
				else cout << "Scalene\n";
			}
		}
	}
	return 0;
}
