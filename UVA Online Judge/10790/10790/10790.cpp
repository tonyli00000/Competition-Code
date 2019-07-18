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
	int m, n, l = 1;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		long long t = 1,x=m+n;
		int i,p=2;
		for (i = x; i > x - 4; i--) {
			t = t*i;
			if (p <= 4 && t%p == 0) {
				t = t / p;
				p++;
			}
		}
		if (m > 2) {
			long long j = 1;
			if (m == 3)j = 1;
			else{
			for (i = m; i > m - 3; i--) {
				p = 2;
				j = j*i;
				if (p <= 3 && j%p == 0) {
					j = j / p;
					p++;
				}
			}
			t = t - j*n;
		}
		if (n > 2) {
			long long j = 1;
			if (n == 3)j = 1;
			else {
				for (i = n; i > n - 3; i--) {
					p = 2;
					j = j*i;
					if (p <= 3 && j%p == 0) {
						j = j / p;
						p++;
					}
				}
			}
			t = t - j*m;
		}
		cout << "Case " << l << ": ";
		cout << t << "\n";
		l++;
	}
	return 0;
}
