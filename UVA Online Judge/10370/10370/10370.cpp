// 10370.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long i, j, k, average, s, a[1002], b,t,sum;
float c;


int main()
{
	cin >> t;
	b = 0;
	for (i = 1; i <= t; i++)
	{
		average = 0;
		b = 0;
		c=0;
		cin >> s;
		sum = 0;
		for (j = 0; j < s; j++)
		{
			cin >> a[j];
			sum = sum + a[j];
		}
		average = sum / s;
		for (k = 0; k < s; k++)
		{
			if (a[k]>average)b = b + 1;
		}
		
		//c = b;
		c = b * 100.0 / s;
		std::cout <<fixed<<setprecision(3) << c<<"%\n";
		
	}
	return 0;
}

