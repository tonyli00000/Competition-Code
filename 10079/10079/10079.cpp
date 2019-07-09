#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

long long t;
int main()
{
	while (cin >> t && t>=0) {
		cout << 1 + (1 + t)*t / 2<<"\n";
	}
	return 0;
}
