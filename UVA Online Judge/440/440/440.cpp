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

int main() {
	int n, x, pos, cont, cities;
	bool ok;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int x = 2;; x++) {
			cities = n - 1;
			pos = (x - 1) % cities;
			ok = true;
			while (cities>1) {
				if (pos == 0) {
					ok = false;
					break;
				}
				cities--;
				pos = (pos + x - 1) % cities;
			}
			if (ok) {
				cout << x << "\n";
				break;
			}
		}
	}
	return 0;
}