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
	int t;
	cin >> t;

	while (t--) {
		int g, l;
		cin >> g >> l;

		int a, b;
		a = g;
		if (l % g != 0) {
			cout << "-1\n";
			continue;
		}

		b = l;

		cout << a << " " << b << "\n";
	}

	return 0;
}