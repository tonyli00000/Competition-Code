// 12646.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int a, b, c, i, j, k, r[3],counts,z;
char g[3];
int main()
{
	g[0] ='A';
	g[1] = 'B';
	g[2] = 'C';
	while (cin >> a >> b >> c)
	{
		z = 0;
		counts = 0;
		k = 0;
		j = 0;
		r[0] = a;
		r[1] = b;
		r[2] = c;

		for (i = 0; i < 3; i++)
		{
			if (r[i] == 1)counts = counts + 1;
			else z = z + 1;
		}
		if ((counts == 3) || (z == 3))cout << "*\n";
		else
			if (counts < z)
			{
				for (i = 0; i < 3; i++)
				{
					if (r[i] == 1)
					{
						k = i;
						break;
					}
				}
				cout << g[k]<<"\n";
			}
			else
			{
				for (i = 0; i < 3; i++)
				{
					if (r[i] == 0)
					{
						j = i;
						break;
					}
				}
				cout << g[j]<<"\n";
			}
	}
	return 0;
}

