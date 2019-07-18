// 499.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x, a[100], q[100], b[200], c, v, w[100], g, z, f;
string y, s[100], o;


int main()
{

	while (getline(cin, y))
	{
		x = 0;
		z = 0;
		c = 0;
		f = 0;
		c = y.length();
		g = 0;
		for (i = 0; i < 100; i++)
		{
			w[i] = 0;
			a[i] = 0;
			q[i] = 0;
			s[i] = "";
			
		}
		for (i = 0; i < c; i++)
		{
			
			if ((y[i] >= 32) && (y[i]<=64))
			{
				y.erase(i, 1);
				c = c - 1;
			}
			if ((y[i] >= 91) && (y[i] <= 96))
			{
				y.erase(i, 1);
				c = c - 1;
			}
			q[i] = y[i];
		}
		for (i = 0; i < c; i++)
		{
			for (j = 0; j <= x; j++)
			{
				if (q[i] == w[j])
				{
					a[j] = a[j] + 1;
					g = 1;
				}
				else g = 0;
			}
			if (g == 1)
			{
			}
			else
			{
				w[x] = q[i];
				a[i] = a[i] + 1;
				x = x + 1;
			}
		}
		for (i = 0; i < c; i++)
		{
			if (a[i]>z)
			{
				z = a[i];
				s[0] = w[i];
				f = 1;
				
			}
			if (a[i] == z){
				f = f + 1;
				s[f] = w[i];
				
			}
		}
		for (i = 1; i <= f; i++)
			for (j = i + 1; j <= f; j++)
			{
				if (s[i] > s[j])
				{
					o = s[i];
					s[i] = s[j];
					s[j] = o;
					break;
				}
			}
		for (i = 1; i <= f ; i++)cout << s[i];
		cout <<" "<<z << "\n";
	}
	return 0;
}

