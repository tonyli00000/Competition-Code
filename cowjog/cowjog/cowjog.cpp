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
	long long n;
	cin >> n;
	vector<long long> S;
	for (long long i = 0; i < n; i++) {
		long long x, s;
		cin >> x >> s;
		S.push_back(s);
	}

	long long ans = 1;
	long long  slow = S[n - 1];
	for (long long i = n - 2; i >= 0; i--) {
		if (S[i] > slow);
		else {
			ans++;
		}
		slow = min(slow, S[i]);
	}
	cout << ans << "\n";
	return 0;
}