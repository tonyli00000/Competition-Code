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

long long n,q,i,j,k;
vector<long long>hay;
long solve(long keyVal)
{
	long long x = 0, y = n - 1, z;
	while (x < y) {
		z = (x + y) / 2;
		if (hay[z] == keyVal) return z + 1;

		if (hay[z] > keyVal) y = z;
		else {
			if (hay[z] < keyVal) x = z + 1;
		}
	}
	if (x == y) {
		if (hay[x] == keyVal) return x + 1;
		else return x;
	}
	return 0;
}
int main()
{
	cin >> n >> q;
	for (i = 0; i < n; i++) {
		cin >> k;
		hay.push_back(k);
	}
	sort(hay.begin(), hay.end());
	while (q--) {
		long long a, b;
		cin >> a >> b;
		a--;

		cout << solve(b) - solve(a) << "\n";
	}
    return 0;
}

