// 10008.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x[15], a, c, g[52], b, d, v, l, f;
string y, s;



int main()
{
	cin >> a;
		b = 0;
		for (i = 0; i <= a; i++)
		{
			getline(cin, y);
			c = y.length();


			for (j = 0; j<c; j++)
			{
				if ((y[j] >= 'A') && (y[j] <= 'Z'))g[y[j] - 'A'] = g[y[j] - 'A'] + 1;
				if ((y[j] >= 'a') && (y[j] <= 'z'))g[y[j] - 'a'] = g[y[j] - 'a'] + 1;
			}

		}
		for (j = 0; j < 52; j++)
		{
			if (g[j] != 0)
			{
				for (k = j; k < 52; k++)
				{
					if (g[k]>g[j])
					{
						f = 0;
						break;
					}
					else f = 1;
				}
				if (k==52)
				{
					cout << char(j + 'A') << " ";
					cout << g[j] << "\n";
					g[j] = 0;
					j = -1;
				}
			}
		}
	return 0;
}

