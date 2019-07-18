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
#define pi 2*acos(0)
using namespace std;

int main()
{
	double r, n;
	while (cin >> r >> n) {
			
		cout << fixed << setprecision(3) << 1.0*n*(r*1.0*r*sin(2.0*pi/n)/2) << "\n";
	}
	return 0;
}
