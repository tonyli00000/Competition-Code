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
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int n,y;
		cin >> n;
		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i == n / 2)y = x;
		}
		cout << "Case " << k + 1 << ": " << y << "\n";
	}
	return 0;
}