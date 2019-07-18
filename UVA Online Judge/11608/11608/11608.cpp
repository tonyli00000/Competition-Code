#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x[12], y[12], t, a, b, c, i, j, k, z;
int main()
{
	while ((cin >> t) && (t >= 0))
	{
		for (i = 0; i < 12; i++)cin >> x[i];
		for (i = 0; i < 12; i++)cin >> y[i];
		cout << "Case " << a + 1 << ":\n";
		b = 0;
		z = t;
		while (b < 12)
		{
			if (z < y[b]){
				cout << "No problem. :(" << "\n";
			}
			else
			{
				z = z - y[b];
				cout << "No problem! :D" << "\n";
				
			}
			z = z + x[b];
			b = b + 1;
		}
			a = a + 1;
	}
	return 0;
}
