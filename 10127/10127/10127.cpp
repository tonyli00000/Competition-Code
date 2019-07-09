// 10127.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long long x, n, p, i, j, k, sum, z, a, counts;


int main()
{
	while (cin >> n)
	{
		a = 1;
		z = 1;
		sum = 0;
		x = 0;
		counts = 0;
		while (a != 0)
		{
			sum = a * 10 + 1 - (sum / n)*n;
			a = sum%n;
			
			counts = counts + 1;
		}

		if (n == 1)cout << 1 << "\n";
			
		else cout << counts+1 << "\n";
	}
	return 0;
}

