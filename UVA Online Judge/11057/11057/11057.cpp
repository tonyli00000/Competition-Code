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

int main()
{
	long i, j, k, t;
	while (cin >> t) {
		vector<long> n;
		map<long,bool> l;
		for (i = 0; i < t; i++) {
			long x;
			cin >> x;
			n.push_back(x);
			l[x] = true;
		}
		cin >> k;
		long a = -1000000, b = 1000000;
		for (i = 0; i < t; i++) {
			if (l[n[i]] && l[k - n[i]] && abs(n[i] - (k - n[i])) < abs(a - b)) {
				a = n[i];
				b = k - n[i];
			}
		}
		cout << "Peter should buy books whose prices are "<<min(a,b) << " and " << max(a,b) << ".\n\n";
	}
	return 0;
}
