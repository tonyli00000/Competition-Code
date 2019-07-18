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
	long long i, j, k;
	long long a, b;
	long long prime[50000];
	bool p[50000];
	int top = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	for (i = 3; i < 50000; i += 2) p[i] = true;
	for (i = 3; i < 50000; i += 2)
	{
		if (p[i]) {
			prime[top] = i;
			top++;
			int i2 = i + i;
			for (j = i * 3; j < 50000; j += i2) p[j] = false;
		}
	}

	while (cin >> a >> b) {
		long long minset[2], maxset[2],min=1000000,max=0;
		bool flag = false;
		long long n;
		for (i = a; i <= b; i++) {
			if (!flag && p[i]) {
				n = i;
				flag = true;
			}
			else {
				if (flag && p[i]) {
					if (min > i - n) {
						min = i - n;
						minset[0] = n;
						minset[1] = i;
						flag = false;
					}
					if (max > i - n) {
						max = i - n;
						maxset[0] = n;
						maxset[1] = i;
						flag = false;
					}
				}
			}
		}
		if (max == 0)cout << "There are no adjacent primes.\n";
		else cout << minset[0] << "," << minset[1] << " are closest, " << maxset[0] << "," << maxset[1] << " are most distant.\n";
	}
	return 0;
}
