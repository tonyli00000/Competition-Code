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
	vector<pair<int, int>>checkpoint;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		checkpoint.push_back(make_pair(x, y));
	}
	for (int i = 1; i < t - 1; i++) {

	}
	return 0;
}
