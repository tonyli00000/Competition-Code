#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 1000000
using namespace std;
long i, j, k, a[45], b, n, x[10000], y, z, t, top, prime[MAXN], i2, f, increase[10000], c, l[10000], m;
bool p[MAXN];
int main()
{
	top = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
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
	cin >> t;
	for (i = 0; i < t; i++){
		cin >> n;
		cin >> a[0];
		cin >> a[1];
		b = 2;
		for (j = 0; j < 1000; j++){
			l[j] = 0;
			x[j] = 0;
			increase[j] = 0;
		}
		while (b <= n){
			for (j = 0; j <= c; j++){
				l[j] = x[j];
				x[j] += increase[j];
				increase[j] = l[j];
			}
			if (b == 2){
				a[b] = a[b - 1] * a[b - 2];
				for (j = 0; j < top; j++){
					if (a[b] % prime[j] == 0)break;
					m = long(sqrt(a[b]));
					if (prime[j]>m)f = 1;
				}
				if (f == 1){
					for (j = 0; j < top; j++){
						if (prime[j] == a[b]){
							x[j] += 1;
							break;
						}
					}
				}
				else{
					for (j = 0; j < top; j++){
						if (prime[j] <= a[b]){
							while (a[b] % prime[j] == 0){
								x[j] += 1;
								a[b] /= prime[j];
								c = j;
							}
						}
					}
					for (j = 0; j < top; j++){
						if (prime[j] <= a[1]){
							while (a[1] % prime[j] == 0){
								a[1] /= prime[j];
								increase[j] += 1;
							}
						}
						else {
							for (k = 0; k < top; k++){
								if (prime[j] == a[1])increase[j] += 1;
								break;
							}
						}
					}
				}
			}
			b = b + 1;
		}
		for (j = 0; j < 1000; j++){
			if (x[j] != 0)cout << prime[j] << " " << x[j] << "\n";
			x[j] = 0;
		}
		
			cout << "\n";
	}
	return 0;
}
