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
	int x, y, z;
	while (cin >> x >> y >> z && x) {
		vector<int> a;
		a.push_back(x);
		a.push_back(y);
		a.push_back(z);
		sort(a.begin(), a.end());
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])cout << "right\n";
		else cout << "wrong\n";
	}
	
	
	return 0;
}
