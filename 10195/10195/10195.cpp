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
	while (cin >> a >> b >> c){
		double r,area;
		if (!a || !b || !c)r = 0;
		else{
			double s = (double)(a + b + c) / 2;
			area = sqrt(s*(s - a)*(s - b)*(s - c));
			r = 2.0*area / (a + b + c);
		}
		cout << fixed<<setprecision(3)<<"The radius of the round table is: " << r << "\n";
	}
	return 0;
}
