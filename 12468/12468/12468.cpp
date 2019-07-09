#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	int i, j, k, m, n;
	while (cin >> m >> n) {
		if (m == -1 && n == -1)break;
		int max = 100;
		if (abs(m - n) < max)max = abs(m - n);
		if (m + 100 - n < max)max = m + 100 - n;
		if (n + 100 - m < max)max = n + 100 - m;
		cout << max << "\n";
	}
	return 0;
}
