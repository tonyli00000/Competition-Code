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
	int a, b, c, i, j, k;
	cin >> t;

	for (k = 0; k < t; k++) {
		bool flag = false;
		cin >> a >> b >> c;
		int x, y, z;
		for (x = -100; x <= 100 && !flag; x++) {
			for (y = -100; y <= 100 && !flag; y++) {
				for (z = -100; z <= 100 && !flag; z++) {
					if (x != y && y != z && x != z) {
						if (x + z + y == a && x*y*z == b && x*x + y*y + z*z == c) {
							cout << x << " " << y << " " << z << "\n";
							flag = true;
						}
					}
				}
			}
		}
		if (!flag)cout << "No solution.\n";
	}
	return 0;
}
