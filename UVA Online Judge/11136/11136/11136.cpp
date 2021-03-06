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
	long long i, j, k, n;
	while (cin >> n && n != 0) {
		multiset <long long> p;
		long long sum = 0;
		for (k = 0; k < n; k++) {
			long long t;
			cin >> t;
			for (i = 0; i < t; i++) {
				long long x;
				cin >> x;
				p.insert(x);
			}
			if (p.size() >= 2) {
				multiset <long long>::iterator it=p.begin();
				multiset<long long>::reverse_iterator rit=p.rbegin();
				sum += *rit - *it;
				p.erase(p.find(*it));
				p.erase(p.find(*rit));
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
