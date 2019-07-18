// p11764.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int high, low, a, b,d, t, i, j, n;


int main()
{
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		high = 0;
		low = 0;
		b = 0;
		cin >> d;
		for (j = 2; j <= n; j++)
		{
			cin >> a;
			if (d < a) high = high + 1;
			if (d > a) low = low + 1;
			d = a;

		}

		cout << "Case " << i << ": " << high << " " << low<<"\n";
	}
	return 0;
}

