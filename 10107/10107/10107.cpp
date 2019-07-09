#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long x[10001], n, i, j, k, b;
int main()
{
	n = 0;
	while (cin >> x[n])
	{
		k = x[n];
			for (i = n; i >= 0; i--)
			{
					if (x[i]<=x[i-1])
					{
						b = x[i-1];
						x[i-1] = x[i];
						x[i] = b;
					}
				
			}
		
		if ((n + 1) % 2 == 0)cout << (x[n / 2] + x[(n / 2) + 1]) / 2 << "\n";
		else cout << x[n / 2]<<"\n";
		n = n + 1;
	}
	return 0;

}