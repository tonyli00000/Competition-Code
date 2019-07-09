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
	int t,tc=0;
	cin >> t;
	while (t--) {
		int r;
		cin >> r;
		double ratio = r*1.0 / 20;
		cout << fixed << setprecision(0) << "Case " << ++tc << ": \n" << ratio*-45 << " " << ratio * 30 << "\n" << ratio * 55 << " " << ratio * 30 << "\n" << ratio * 55 << " " << ratio*-30 << "\n" << ratio*-45 << " " << ratio*-30 << "\n";
	}
	return 0;
}
