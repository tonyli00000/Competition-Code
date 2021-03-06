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

using namespace std;

int main()
{
	int t;
	cin >> t;
	long long i, j, k;
	for (k = 0; k < t; k++) {
		long long x, y;
		cin >> x >> y;
		multiset <long long> a;
		multiset <long long> b;
		multiset <long long>::iterator it;
		for (i = 0; i < x; i++) {
			long long p;
			cin >> p;
			a.insert(p);
		}
		for (i = 0; i < x; i++) {
			long long p;
			cin >> p;
			b.insert(p);
		}
		long long ct = 0;
		multiset<long long>::iterator p = b.find(*it);
		for (it = a.begin(); it != a.end(); it++) {
			if (p != b.end()) {
				ct++;
				b.erase(p);
			}
		}
		cout << x+y-ct*2 << "\n";
	}
	return 0;
}
