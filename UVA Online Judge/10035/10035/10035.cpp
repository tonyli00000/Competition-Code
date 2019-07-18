#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

long long m, n, a, b, c;
int total;

int main()
{
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)break;
		int ct = 0;
		c = 0;
		while ((m != 0) || (n != 0))
		{
			a = m % 10; b = n % 10;
			c += a + b;
			if (c > 9) ct++;
			m = m / 10;
			n = n / 10;
			c = c / 10;
		}
		if (ct == 0) cout << "No carry operation.\n";
		if (ct == 1) cout << "1 carry operation.\n";
		if (ct > 1) cout << ct << " carry operations.\n";
	}

	return 0;
}