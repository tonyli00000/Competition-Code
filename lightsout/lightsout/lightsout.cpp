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

long i, j, k;
vector<pair<long, long>>coord;
int main()
{
	int n;
	cin >> n;
	for (i = 0; i < n; i++) {
		long x, y;
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

    return 0;
}

