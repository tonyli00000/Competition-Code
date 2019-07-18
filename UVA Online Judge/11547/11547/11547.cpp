#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long long t, n,i;
int main()
{
	cin >> t;
	for (i = 0; i < t; i++){
		cin >> n;
		cout << abs(((((n * 63) + 7492) * 5 - 498) % 100) / 10) << "\n";
	}
	return 0;
}
