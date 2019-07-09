#include <cstdio>
#include <cstring>
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
using namespace std;
int main() {
	int t, n;
	double x, y, c, sum;
	cin >> t;
	for (int k = 0; k < t;k++) {
		if (k != 0)cout << "\n";
		cin >> n >> x >> y;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			sum += (n - i) * c;
		}
		cout << fixed<<setprecision(2)<<(n*x + y - 2 * sum) / (n + 1) << "\n";
	}
	return 0;
}
