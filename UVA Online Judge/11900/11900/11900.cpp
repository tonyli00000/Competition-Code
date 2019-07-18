#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x[31], y, z, i, j, k, t, n, p, q, b;
int main()
{
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		cin >> p;
		cin >> q;
		
		for (j = 0; j < n; j++)
		{
			cin >> x[j];
		}
		for (j = 0; j < n; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				if (x[k] < x[j])
				{
					z = x[j];
					x[j] = x[k];
					x[k] = z;
				}
			}
		}
		b = -1;
		y = 0;
		while ((y <= q) && (b+1<=p))
		{
			b = b + 1;
			if (b == n)break;
			y = y + x[b];
			x[b] = 0;
		}
		cout << "Case "<<i<<": "<<b<<"\n";
		for (j = 0; j < n; j++)x[j] = 0;
	}


	return 0;
}
