// 12704.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>

using namespace std;
double x,y, r, d, f,t,i;


int main()
{
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> x >> y >> r;
		d = sqrt(x*x + y*y);
		//if (d == 0)
			//std::cout << fixed << setprecision(2) << 1.0*(r - d) << " " << 1.0*(r - d) << "\n";
		std::cout << fixed << setprecision(2) << (r - d)*1.0 << " " << 1.0*(2 * r - (r-d))<<"\n";
	}
	return 0;
}

