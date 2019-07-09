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
#define pi 3.1415926535
using namespace std;

int main()
{
	int x, y, z;
	while (cin >> x >> y >> z) {
		double s = (x + y + z)/2;
		double tri = sqrt(s*1.0*(s - x*1.0)*(s - y*1.0)*(s - z*1.0));
		double r = 2.0*tri / 2.0 / s;
		double sc = r*r*pi;
		double rr = x*y*z*1.0 / (sqrt((x + y + z)*(y + z - x)*(z + x - y)*(x + y - z)));
		double circle = rr*rr*pi-tri;
		tri -= sc;
		cout << fixed << setprecision(4) << circle << " " << tri << " " << sc << "\n";
	}
	return 0;
}
