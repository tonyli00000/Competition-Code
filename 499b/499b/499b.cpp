// 499b.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, c,str[52],b;
string s, o[52];
int main()
{
	while (getline(cin, s))
	{
		b = 0;
		k = s.length();
		for (i = 0; i < 52; i++)str[i] = 0;
		for (i = 0; i <= k; i++)
		{
			if ((s[i] >= 'A') && (s[i] <= 'Z'))str[(s[i] - 65)] = str[(s[i] - 65)] + 1;
			if ((s[i] >= 'a') && (s[i] <= 'z'))str[(s[i] - 97 + 25)] = str[(s[i] - 97 + 25)] + 1;
		}
		c = 0;
			for (i = 0; i < 52; i++)
			{
				if (str[i]>c)
				{
					c = str[i];
				}
			}

			for (i = 0; i < 52; i++)
			{
				if ((str[i] == c) && (i <= 25))cout << char(i + 65);
				if ((str[i] == c) && (i >= 26))cout << char(i + 72);
			}
			cout << " "<<c;
		
	}
	return 0;
}

