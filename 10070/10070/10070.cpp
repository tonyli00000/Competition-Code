#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;

int main()
{
	string s;
	int i, j, k,a,b,c,d,e,leap=0,hulu=0,bulu=0,t=0;
	while (cin >> s) {
		if (t++)cout << "\n";
		int i, j, k, a=0, b=0, c=0, d=0, e=0, leap = 0, hulu = 0, bulu = 0;
		for (i = 0; i < s.length(); i++)
		{
			a = a * 10 + (s[i] - '0');
			a = a % 4;
		}
		if (a == 0)
		{
			for (i = 0; i<s.length(); i++)
			{
				b = b * 10 + (s[i] - '0');
				b = b % 100;
			}
			if (b == 0)
			{
				for (i = 0; i<s.length(); i++)
				{
					c = c * 10 + (s[i] - '0');
					c = c % 400;
				}
				if (c == 0)
					leap = 1;
			}
			else
				leap = 1;
		}
		for (i = 0; i<s.length(); i++)
		{
			d = d * 10 + (s[i] - '0');
			d = d % 15;
		}
		if (d == 0)
			hulu = 1;
		if (leap == 1)
		{
			for (i = 0; i<s.length(); i++)
			{
				e = e * 10 + (s[i] - '0');
				e = e % 55;
			}
			if (e == 0)
				bulu = 1;
		}
		if (leap == 1)cout << "This is a leap year.\n";
		if (hulu == 1)cout<<"This is huluculu festival year.\n";
		if (bulu == 1)cout<<"This is bulukulu festival year.\n";
		if (leap == 0 && hulu == 0 && bulu == 0)cout<<"This is an ordinary year.\n";
	}
	return 0;
}
