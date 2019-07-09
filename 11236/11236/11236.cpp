#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
//#include <boost/math/special_functions/round.hpp>

using namespace std;

int main()
{
	double a, b, c, d;
	for (int a = 1; a < 126; ++a) {
		int blim = (2002 - a) / 3;
		for (int b = a; b <= blim; ++b) {
			int clim = (2001 - (a + b)) / 2;
			for (int c = b; c <= clim; ++c) {
				int sum = a + b + c;
				long long div = (long long)(a)* b * c;
				if (div <= 1000000) continue;
				double d = sum * 1e6 / (div - 1e6);
				if (d < c) continue;
				if (d - floor(d) < 1e-6) {
					sum = a + b + c + d;
					if (sum <= 2000)
						cout << fixed << setprecision(2) << a / 100.0 << " " << b / 100.0 << " " << c / 100.0 << " " << d / 100.0 << "\n";
				}
			}
		}
	}
	/*for (a = 0.08; a <= 1.25; a += 0.01) {
		for (b = 0.01; b <= 20.00-a; b += 0.01) {
			for (c = 0.01; c <= 20.00-a-b; c += 0.01) {
				for (d = 0.01; d <= 20.00-a-b-c && a*b*c*d<a+b+c+d; d += 0.01) {
					if (roundf((a + b + c + d)*100)/100 == roundf(a*b*c*d * 100) / 100) {
						cout << a << " " << b << " " << c << " " << d << "\n";
					}
				}
			}
		}
	}*/
	return 0;
}
