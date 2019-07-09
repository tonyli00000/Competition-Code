// p11799.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int s, t, a, b, c, d,e,f,g,i,n;
int main()
{
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		s = 0;
		for (g = 1; g <= n; g++)
		{
			cin >> a;
			if (s < a) s = a;

		}
		
		cout << "Case " << i << ": " << s<<"\n";
		

	}
	return 0;
}

