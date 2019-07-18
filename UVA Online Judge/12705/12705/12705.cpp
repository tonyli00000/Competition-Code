#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, sum, x[7][7], t, c, b, p[52],g[36],a;
string y;
int main()
{
	cin >> t;
	for (k = 0; k < t; k++)
	{
		if (k == 0)getline(cin, y);
		sum = 0;
		getline(cin, y);
		c = y.length();
		for (i = 0; i < 52; i++)p[i] = 0;
		for (i = 0; i < 36; i++)g[i] = 0;
		for (i = 0; i < c; i++)
		{
			if ((y[i] >= 'A') && (y[i]<= 'Z'))p[y[i] - 'A'] ++;
			if ((y[i] >= 'a') && (y[i] <= 'z'))p[y[i] - 'a'] ++;
			if ((y[i] >= '0') && (y[i] <= '9'))p[y[i] - '0' + 26]++;
			
		}
		b = 0;
		for (i = 0; i < 52; i++)
		{
			for (j = i + 1; j < 52; j++)
			{
				if (p[j] < p[i])
				{
					c = p[i];
					p[i] = p[j];
					p[j] = c;
				}
			}
		}
		c = y.length();
		b = 0;
		for (i = 1; i < 7; i++)
		{
			for (j = 1; j < 7; j++)
			{
				g[b] = i + j;
				b = b + 1;
			}
		}
		for (i = 1; i < 36; i++)
		{
			for (j = i + 1; j < 36; j++)
			{
				if (g[j] <= g[i])
				{
					c = g[j];
					g[j] = g[i];
					g[i] = c;
				}
			}
		}
		b = 0;

		for (j = 51; j >= 0; j--)
		{
			
		sum = p[j] * g[b] + sum;
		if (p[j]!=0)b = b + 1;
		else break;
		}
		
		cout << sum<<"\n";
		
	}
	return 0;
}
