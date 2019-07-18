
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

#define PI 2*acos(0.0)
int main()
{
	int test, i, D, L;
	double a, b, ans;
	cin >> test;
	for (i = 0; i<test; i++)
	{
		cin >> D >> L;
		a = L / 2.0;
		b = sqrt((L / 2.0)*(L / 2.0) - (D / 2.0)*(D / 2.0));
		ans = PI*a*b;
		cout << fixed << setprecision(3) << ans << "\n";
	}
	return 0;
}

