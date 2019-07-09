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
	string line,copy;
	int i, j, k;
	while (cin >> line) {
		string a, b;
		sort(line.begin(), line.end());
		b= line;
		for (i = 0; i < line.length() / 2; i++) {
			char temp = line[line.length() - 1 - i];
			line[line.length() - 1 - i] = line[i];
			line[i] = temp;
		}
		a = line;
		long long x=0, y=0;
		long long m = 1;
		for (i = 0; i < a.length(); i++) {
			x += m*(b[i] - '0');
			m *= 10;
		}
		m = 1;
		for (i = 0; i < a.length(); i++) {
			y += m*(a[i] - '0');
			m *= 10;

		}
		cout << a << " - " << b << " = " << x - y << " = 9 * " << (x - y) / 9 << "\n";
	}
	return 0;
}
