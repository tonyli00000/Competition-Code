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
#include <algorithm>

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection() {
	double lo = 0, hi = 1;
	while (lo + (0.0000001) < hi) {
		double x = (lo + hi) / 2;
		if (f(lo) * f(x) <= 0)hi = x;
		else lo = x;
	}
	return (lo + hi) / 2;
}

int main() {
	while (cin >> p >> q >> r >> s >> t >> u) {
		if (f(0) * f(1) > 0)cout<<"No solution\n";
		else cout << fixed << setprecision(4) << bisection()<<"\n";
	}

	return 0;
}