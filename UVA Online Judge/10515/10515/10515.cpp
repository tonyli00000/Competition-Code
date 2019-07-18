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
	string a, b;
	int e[10][4];
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j <= 9; j++) {
			int l = pow(j, i);
			e[j][i - 1] = l % 10;
		}
	}
	while (cin >> a >> b) {
		if (a == "0"&&b == "0")break;
		int x, y;
		if (b.length() == 1) {
			y = b[0] - '0';
			if (y == 0)cout << "1\n";
			continue;
		}
		else y = 10 * (b[b.length() - 2] - '0') + b[b.length() - 1] - '0';
		x = a[a.length() - 1] - '0';

				int rem = y % 4;
				if (rem == 0)cout << e[x][3]<<"\n";
				else cout << e[x][rem-1] << "\n";
	}
	return 0;
}
