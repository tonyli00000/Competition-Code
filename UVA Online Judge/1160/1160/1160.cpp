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

long p[100005];
int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}
int main()
{
	long m, n, ct = 0, accepted = 0, i, j;
	for (i = 0; i <= 100000; i++) {
		p[i] = i;
	}
	while (cin >> n) {
		if (n != -1) {
			cin >> m;
			if (getroot(n) != getroot(m)) {
				p[getroot(n)] = getroot(m);
				accepted++;
			}
			ct++;
		}
		else {
			for (i = 0; i <= 10000; i++) {
				p[i] = i;
			}
			cout << ct - accepted << "\n";
			ct = 0;
			accepted = 0;
		}
	}
	return 0;
}
