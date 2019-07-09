#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 1100000
using namespace std;
long long top, i, j, k, i2, prime[MAXN], x, y, z, f;
bool p[MAXN];
long long t;
int main()
{
	top = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = false;
	for (i = 3; i < MAXN; i += 2) p[i] = true;
	for (i = 3; i < MAXN; i += 2)
	{
		if (p[i]) {
			prime[top] = i;
			top++;
			i2 = i + i;
			for (j = i * 3; j < MAXN; j += i2) p[j] = false;
		}

	}

	while ((cin >> t)) {

		f = 0;
		x = 0;
		y = 0;
		for (i = 0; i < top; i++) {
			if (x != 0)break;
			if (i > top / 2) {
				f = 1;
				break;
			}
			if (prime[i] + prime[i] > t) {
				f = 1;
				break;
			}
			if (p[t - prime[i]] == true) {
				x = i;
				for (j = 0; j < top; j++) {
					if (prime[j] == t - prime[i]) {
						y = j;
						break;
					}
				}
				break;
			}
		}
		if (f == 1)cout << t<<":\n"<<"NO WAY!\n";
		else cout << t << ":\n"<< prime[x] << "+" << prime[y] << "\n";
	}
	return 0;
}