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
	long long n, t;
	cin >> n >> t;
	vector<long long> speed;
	for (long long i = 0; i < n; i++) {
		long long x, s;
		cin >> x >> s;
		speed.push_back(x + s*t);
	}

	long long ans =0;
	long long slow = speed[n - 1];
	for (long long i = n - 1; i >= 0; i--) {
		if (speed[i] < slow) ans++;
		slow = min(slow, speed[i]);
	}
	cout << ++ans << "\n";
	return 0;
}