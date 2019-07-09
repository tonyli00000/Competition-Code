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
	int t;
	cin >> t;
	while (t--){
		vector<int> sides;
		int x, y, z;
		cin >> x >> y >> z;
		sides.push_back(x);
		sides.push_back(y);
		sides.push_back(z);
		sort(sides.begin(), sides.end());
		if (sides[0] + sides[1] <= sides[2])cout << "Wrong!!\n";
		else cout << "OK\n";
	}
	return 0;
}
