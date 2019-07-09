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
#define MAXN 500000			// total # of prime numbers
#define MAXP 10000000		// highest number to test prime

long long prime[MAXN];
long long n, s, c;
long top;
bool p[MAXP];
long id[MAXP];
int main()
{
	long long i, i2, j, nn;
	top = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	for (i = 3; i < MAXP; i += 2) p[i] = true;
	for (i = 3; i < MAXP; i += 2)
	{
		if (p[i]) {
			prime[top] = i;
			top++;
			i2 = i + i;
			for (j = i * 3; j < MAXP; j += i2) p[j] = false;
		}
	}

	int t, k,q[8];
	cin >> t;
	for (k = 0; k < t; k++) {
		string line;
		cin >> line;
		int len = line.length();
		for (i = 0; i < line.length(); i++) {
			q[i] = line[i] - '0';
		}
		int ct = 0;
		for (int l = 0; l <= line.length(); l++) {
			for (j = l+1; j <= line.length(); j++) {
				do {
					long m = 1, sum = 0;
					for (i = len - 1; i >= 0; i--) {
						sum += m*(q[i]);
						m *= 10;
					}
					if (p[sum])ct++;
				} while (next_permutation(q+l, q + j));
			}
		}
		cout << ct << "\n";
	}
	return 0;
}
