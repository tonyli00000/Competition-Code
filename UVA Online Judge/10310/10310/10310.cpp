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

double dist(double x1, double y1, double x2, double y2){
	return (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}
int main()
{
	int n;
	while (cin >> n){
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bool flag = true;
		while (n--){
			double x, y;
			cin >> x >> y;
			if (dist(x1,y1,x,y)*2<=
		}
	}
	return 0;
}
