#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long l, w, h, a, i, j, k, s[102], v[102], t;
double f;

int main()
{
	while ((cin >> t) && (t != 0))
	{
		a = 0;
		f = 0;
		for (i = 0; i < 103; i++)
		{
			s[i] = 0;
			v[i] = 0;
		}
		for (i = 0; i < t; i++)
		{
			cin >> l >> w >> h;
			s[i] = l*w;
			v[i] = l*w*h;
			if (i == 0)
			{
				f = 1 / (1.0*h);
				a = v[i];
			}
			else
				if ((f >= s[i] * 1.0 / v[i]))
				{
					if (f == s[i] * 1.0 / v[i])
					{
						f = s[i] * 1.0 / v[i];
						if (v[i]>a)
							a = v[i];
					}
					else
					{
						f = s[i] * 1.0 / v[i];
						a = v[i];
					}
				}
		}
		cout << a << "\n";
	}
	return 0;

}