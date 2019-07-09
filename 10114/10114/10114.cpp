#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int d;
long double x, loan, v, payment;
long double dep[105], dd;
int n, i, j, t;

int main()
{
	while (cin >> d >> x >> loan >> n, d >= 0) {
		for (i = 0; i < n; i++) {
			cin >> t >> dd;
			for (j = t; j <= d; j++) dep[j] = dd;
		}

		v = (x + loan) * (1 - dep[0]);
		payment = loan / d;

		i = 0;
		if (loan >= v)
			for (i = 1; i <= d; i++) {
				v = v * (1 - dep[i]);
				loan -= payment;
				if (loan < v) break;
			}
		if (i == 1) cout << i << " month\n";
		else cout << i << " months\n";
	}
	return 0;
}