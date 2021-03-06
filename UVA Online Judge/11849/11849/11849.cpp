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
	long long m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		set <long long> jack;
		set <long long> jill;
		long long i, j, k;
		for (i = 0; i < m; i++) {
			cin >> k;
			jack.insert(k);
		}
		for (i = 0; i < m; i++) {
			cin >> k;
			jill.insert(k);
		}
		if (jack.empty() || jill.empty())cout << "0\n";
		else {
			set <long long>::iterator it;
			long long ct = 0;
			for (it = jack.begin(); it != jack.end(); it++) {
				if (jill.find(*it) != jill.end())ct++;
			}
			cout << ct << "\n";
		}
	}
	return 0;
}
