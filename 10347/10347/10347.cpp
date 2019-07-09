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

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c) {
		double s = (a + b + c) / 2.0;
		double area = (4.0 / 3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
		if (area > 0)cout << fixed << setprecision(3) << area << "\n";
		else cout << "-1.000/n";
	}
	return 0;
}
