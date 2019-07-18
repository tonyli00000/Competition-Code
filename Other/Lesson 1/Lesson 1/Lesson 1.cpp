#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int a, b, c;

int main()
{
	// calculate the sum of a and b
	while (cin >> a >> b)
	{
		if (a > b) c = a;
		else c = b;
		cout << c << "\n";
	}
	return 0;
}
