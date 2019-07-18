// 202.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int  i, j, k, places, s, b, g, c, sum, counts, x[10002], r, denominator,numerator,y[10002],p;





int main()
{
	p = 0;
	while (cin >> numerator >> denominator)
	{
		p = p + 1;
		if (p>1)cout << "\n";
		for (i = 0; i < 10002; i++)
		{
			x[i] = 0;
			y[i] = 0;
		}
		r = numerator;
		b = 0;
		counts = 0;
		j = 1;
		c = 0;
		g = 0;
		s = 0;
		while (j != 0)
		{
			//if (denominator == 1)s = 2;
			if (r / denominator == 0)
			{
				x[b] = r;
				r = 10 * r;
				//counts = counts + 1;
			}
			else
			{
				y[b] = r / denominator;
				r = r - r / denominator*denominator;
				if (r == 0)
				{
					s = 1;
					break;
				}
				x[b] = r;
				r = r * 10;
				counts = counts + 1;
			}
			for (i = 0; i < b; i++)
			{
				if (x[i] == x[b])
				{
					j = 0;
					c = i;
					g = b;
				}
			}
			b = b + 1;
		}
	

		if (s == 1)
		{
			cout << numerator << "/" << denominator << " = ";
			cout << y[0] << ".";
			for (k = 1; k <= b; k++)
			{
				//if (k == 1)cout << y[0]<<".";
				cout << y[k];
			}
			cout << "(0)\n";
			cout << "   1 = number of digits in repeating cycle\n";
			cout << "\n";
		}
		if (s==0)
		{
			cout << numerator << "/" << denominator << " = ";
			if (g - c > 50)
			{
				for (k = 0; k <= c; k++)
				{
					if (k == 0)cout << y[0]<<".";
					else cout << y[k];

				}
				for (k = c + 1; k <= 50; k++)
				{
					if (k == c + 1)cout << "(";
					cout << y[k];
					if (k == 50)cout << "...)\n";
				}
				cout << "   " << g - c << " = number of digits in repeating cycle\n";
				cout << "\n";
			}
			else
			{
				for (k = 0; k <= c; k++)
				{
					if (k == 0)cout << y[0]<<".";
					else cout << y[k];

				}
				for (k = c + 1; k <= g; k++)
				{
					if (k == c + 1)cout << "(";
					cout << y[k];
					if (k == g)cout << ")\n";
				}
				cout << "   " << g - c << " = number of digits in repeating cycle\n";
				cout << "\n";

			}
			//if (s == 2)
			//{
			//	cout << numerator << "/" << denominator << " = "<<numerator*1.0/denominator
			//}
		}
	}
	return 0;
}

