#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 1000000
using namespace std;
long long i, j, k, top, prime[MAXN / 2], i2, n, o, p, c, q, a[MAXN],sum[MAXN],d;
bool b[MAXN];
int main()
{
		prime[0] = 2;
		d = 1;
		a[2] = 1;
		for (i = 3; i <= MAXN; i ++){
			k = 0;
			for (j = 0; (j < d) && (prime[j] <= sqrt(i)); j++){
				if (i % prime[j] == 0){
					k = 1;
					a[i] = 1 + a[i / prime[j]];
					break;
				}
			}
			if (k == 0){
				prime[d] = i;
				a[i] = 1;
				d = d + 1;
			}

	}
	a[0] = 0;
	a[1] = 0;
	sum[2] = 1;
	for (i = 3; i <= MAXN; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	sum[0] = 0;
	sum[1] = 0;
	while (cin >> n)
	{
		cout << sum[n] << "\n";

	}

	return 0;
}
