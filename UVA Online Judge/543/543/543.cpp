#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 500000			// total # of prime numbers
#define MAXP 1000002		// highest number to test prime

long long prime[MAXN];
long long n, s, c;
long top;
bool p[MAXP];
long id[MAXP];

int isprime(long long key)
{
	long i;

	for (i = 1; i < top; i++)
		if (key % prime[i] == 0) return 0;
	return 1;
}

int main()
{
	long long i, i2, j, nn;

	// generate all prime numbers using sieve
	top = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	id[0] = 0;
	id[1] = 0;
	id[2] = 0;
	for (i = 3; i < MAXP; i += 2) p[i] = true;
	for (i = 3; i < MAXP; i += 2)
	{
		if (p[i]) {
			prime[top] = i;
			top++;
			i2 = i + i;
			for (j = i * 3; j < MAXP; j += i2) p[j] = false;
		}
		id[i] = top;
		id[i + 1] = top;
	}

	while (cin >> n, n > 0)
	{
		for (i = 1; i < top; i++)
			if (p[n - prime[i]]) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
				break;
			}
	}

	return 0;
}
