#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x, a, z, q, c;
string y, s;
char b;
int main()
{
	while (getline(cin,y))
	{
		
		c = y.length();
		y.insert(c, " ");
		z = 0;
		x = 0;
		q = 0;
		for (i = 0; i < c; i++)
		{
			if ((y[i] >= 65) && (y[i] <= 90))z = 1;
			if ((y[i] >= 97) && (y[i] <= 122))z = 1;
			if ((y[i] >= 32) && (y[i] <= 64))z = 0;
			if ((y[i] >= 91) && (y[i] <= 96))z = 0;
			if (z == 1)
			{
				q = q + 1;
			}
			else
			{
				if (q!=0)
				x = x + 1;
				q = 0;
			}
		}
		if (z==1)cout << x+1 << "\n";
		else cout << x  << "\n";


		}
		return 0;
	}




