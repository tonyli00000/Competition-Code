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
	int T, n;

	cin >> T;

	long long f[41];

	f[0] = 1;
	f[1] = 1;
	f[2] = 5;

	for (int i = 3; i <= 40; ++i)
		f[i] = f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3];

	while (T--) {
		cin >> n;
		cout << f[n] << "\n";
	}

	return 0;
}