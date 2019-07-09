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

int main() {
	int n;
	while (cin >> n) {
		vector<long long> a(n);
		long long tot = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			tot += a[i];
		}
		tot /= n;
		a[0] = 0;
		for (int i = 1; i < n; ++i)
			a[i] = a[i - 1] + tot - a[i];

		sort(a.begin(), a.end());
		long long mid = (a[n >> 1] + a[(n - 1) >> 1]) >> 1;
		long long ans = 0;
		for (int i = 0; i < n; ++i)
			ans += abs(mid - a[i]);
		cout << ans << "\n";
	}
	return 0;
}