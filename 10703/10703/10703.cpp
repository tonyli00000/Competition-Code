// 10703.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long int w, h, n, x1, yy1, x2, y2, i, j, k, blank,spot, tmp;
bool empty[502][502];


int main()
{
	while (cin >> w >> h >> n, (w != 0) || (h != 0) || (n != 0))
	{

		for (j = 0; j < 502; j++)
		{
			for (k = 0; k < 502; k++)
			{
				empty[j][k] = true;
			}
		}
		for (i = 0; i < n; i++)
		{
			cin >> x1 >> yy1 >> x2 >> y2;
			if (x2 < x1) {
				tmp = x1;
				x1 = x2;
				x2 = tmp;
			}
			if (y2 < yy1)
			{
				tmp = yy1;
				yy1 = y2;
				y2 = tmp;
			}
			for (j = x1; j <= x2; j++)
			{
				for (k = yy1; k <= y2; k++)
				{
					empty[j][k] = false;
					blank = 0;
				}
			}
		}
		blank = 0;
		for (j = 1; j <= w; j++)
		{
			for (k = 1; k <= h; k++)
			{
				if (empty[j][k] == true) blank = blank + 1;
			}
		}
		if (blank == 0)cout << "There is no empty spots.\n";
		if (blank == 1)cout << "There is one empty spot.\n";
		if (blank > 1)cout << "There are " << blank << " empty spots.\n";
	}
	return 0;
}

