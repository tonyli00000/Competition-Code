#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long long t, x, y,i;
float p;
int main()
{
	cin >> t;
	for (i = 0; i < t; i++){
		cin >> x >> y;
		p = x / 3;
		if (p != x / 3 * 1.0)x = x/3 + 1;
		else x = x / 3;
		p = y / 3;
		if (p != y / 3 * 1.0)y = y / 3 + 1;
		else y = y / 3;
		cout << x*y << "\n";
	}
	return 0;
}
