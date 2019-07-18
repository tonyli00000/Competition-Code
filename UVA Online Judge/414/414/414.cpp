#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int  n, i, j, k, c[13], a[13], space, z;
string r[13];
int main()
{
	while ((cin >> n) && (n != 0))
	{
		getline(cin, r[0]);
		for (i = 0; i < 13; i++)
		{
			r[i] = " ";
			c[i] = 0;
			a[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			getline(cin, r[i]);
			c[i] = r[i].length();
			
			for (j = 0; j < c[i]; j++)
			{
				if (r[i][j] == 'X')a[i] = a[i] + 1;
			}
		}
		z = 0;
		space = 0;
		for (i = 0; i < n; i++)
		{
				if (a[i] >= z)z = a[i];
		}
		for (j = 0; j < n; j++)
		{
			space = z - a[j] + space;
		}
		cout << space << "\n";
	}
	return 0;

}