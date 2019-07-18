#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int t, i, j, k, c, b, a, x, d, z,o,p;
string y, l, g;
int main()
{
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> y;
		a = y[0]-48;
		b = y[1]-48;
		c = y[3]-48;
		d = y[4]-48;
		x = a * 10 + b;
		k = c * 10 + d;
		z = 24*60 - x*60 - k;
		if (z / 60 >= 12)z = z - 720;
		o = z / 60;
		p = z % 60;
		if (o == 0)o = 12;
		if ((p<10)&&(o<10))cout << "0"<<o << ":" <<"0"<< p << "\n";
		if ((p>=10) && (o<10))cout << "0" << o << ":" << p << "\n";
		if ((p < 10) && (o >= 10))cout << o << ":0" << p << "\n";
		if ((p >= 10) && (o >= 10))cout << o << ":" << p << "\n";
		
	}
	return 0;
}
