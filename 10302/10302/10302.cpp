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
	long double ans,n;
	while (cin >> n) {
		ans = n*n*(n + 1)*(n + 1) / 4;
		cout << ans << "\n";
	}
	return 0;
}