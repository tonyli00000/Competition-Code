#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int a, b, c, t,i,d,e;

int main()
{
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> a >> b >> d;
		if ((a < b) && (b < d)) e = b;
		if ((d < b) && (b < a)) e = b;
		if ((b < a) && (a < d)) e = a;
		if ((d < a) && (a < b)) e = a;
		if ((a < d) && (d < b)) e = d;
		if ((b < d) && (d < a)) e = d;

		cout << "Case " << i << ": " << e<<"\n";
	}
	
	return 0;
}

