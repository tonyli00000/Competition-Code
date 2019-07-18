
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x, y, i, j, number, highest, tmp, z, aa;



int main()
{

	while (cin >> x >> y)
	{
		highest = 0;
		if (y < x)
		{
			z = x;
			aa = y;
			x = y;
			y = z;
		}
		else
		{
			z = x;
			aa = y;
		}
		for (i = x; i <= y; i++)
		{
			tmp = 0;
			number = i;
			while (number > 1)
			{
				if (number % 2 == 0)
				{
					number = number / 2;
					tmp = tmp + 1;
				}
				else
				{
					number = 3 * number + 1;
					tmp = tmp + 1;
				}
			}
			if (tmp > highest)highest = tmp;
		}
		highest = highest + 1;
		cout << z << " " << aa << " " << highest << "\n";
	}
	return 0;
}

