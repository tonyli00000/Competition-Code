#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 100000000
using namespace std;
long long top, i, j, k, i2, prime[MAXN], t, x, y, z, f;
bool p[MAXN];
int main()
{
	top = 1;
	for (i = 0; i < MAXN; i++)p[i] = true;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = false;
	for (i = 4; i < MAXN; i += 2) p[i] = false;
	for (i = 3; i < MAXN; i += 2)
	{
		if (p[i])for (j = i*i; j<MAXN; j += i + i)
				p[j] = false;

	}
	while ((cin >> t) && (t != 0)) {
		f = 0;
		x = 0;
		y = -1;
		int a = 0, b = 0;
		if (t % 2 == 1 && p[t - 2]) {
			cout << t << " is the sum of 2 and " << t - 2<<".\n";
		}
		else {
			int pos = 0;
			for (i = 0; i < 100; i++){
				if (p[t / 2 - i]) {
					pos = i;
					break;
				}
			}
			for (i = 0; i < top; i++)if (t / 2 - pos == prime[i]) {
				pos = i;
				break;
			}
			for (i = pos; i >=0; i--) {
				if (p[t - prime[i]] == true) {
					a = i;
					for (j = 0; j < top; j++) {
						if (prime[j] == t - prime[i]) {
							b = j;
							break;
						}
					}
					x = a;
					y = b;
					break;
					if (a > b) {
						break;
					}
				}
			}

			if (y - x < 0)cout << t << " is not the sum of two primes!" << "\n";
			else cout << t << " is the sum of " << prime[x] << " and " << prime[y] << ".\n";
		}
		
	}
	return 0;
}
