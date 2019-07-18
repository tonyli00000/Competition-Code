#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x, c,d, i, j, k;
double p, o;
int main()
{
	cin >> x;
	for (i = 0; i < x; i++)
	{
		cin >> c;
		cin >> d;
		p = 1.8*c + 32;
		o = p + d;
		cout << "Case " << i + 1 << ": ";
		std::cout << fixed << setprecision(2) << (o*1.0 - 32) / 1.8<<"\n";
	}
	return 0;
}
