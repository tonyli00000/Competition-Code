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
long long f(int n) {
	if (n == 0) return 0;
	long long ans = 0;
	int i, r = (int)floor(sqrt(n));

	if (r*r == n) {
		ans += n / r;
		--r;
	}

	for (i = 1; i <= r; ++i) {
		ans += n / i;
		ans += max(0, int(n / i - r));
	}

	return ans;
}
int main()
{
	int t;
	cin >> t;

	long long i, j, k;
	while (t--) {
		long long x;
		cin >> x;
		cout << f(x) << "\n";
	}
	return 0;
}
