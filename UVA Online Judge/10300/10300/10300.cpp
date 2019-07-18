#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	long long i, j, k, a, b, c, sum;
	int t;
	cin >> t;
	for (k = 0; k < t; k++) {
		int p;
		sum = 0;
		cin >> p;
		for (j = 0; j < p; j++) {
			cin >> a >> b >> c;
			sum += a*c;
		}
		cout << sum << "\n";
	}
	return 0;
}
