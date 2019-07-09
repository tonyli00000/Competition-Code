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

#define PI 3.141592653589793


int main() {

	double x1, y1, x2, y2, x3, y3;
	double a, b, c, S, R;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		b = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
		c = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
		S = 0.5*abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
		R = a*b*c / (4 * S);
		cout << fixed << setprecision(2) << 2 * PI*R << "\n";
	}

	return 0;
}