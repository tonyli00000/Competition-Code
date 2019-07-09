#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 1000000000
using namespace std;
long i, j, k, a[10000], b, c, top, i2, q, l, u, product, z, w;
int prime[MAXN / 4];
bool p[MAXN];
int main()
{
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	top = 1;
	for (i = 3; i < MAXN; i += 2) p[i] = true;
	for (i = 3; i < MAXN; i += 2){
		if (p[i]) {
			prime[top] = i;
			top++;
			i2 = i + i;
			for (j = i * 3; j < MAXN; j += i2) p[j] = false;
		}
	}
	cin >> w;
	for (k = 0; k < w; k++)
	{
		cin >> l;
		cin >> u;
		for (i = l; i <= u; i++)
		{

			c = i;

			if ((p[i] == false)){
				for (j = 0; j <= b; j++)a[j] = 0;
				b = 0;
				for (j = 0; j < top; j++){
					if (prime[j] <= c){
						while (c%prime[j] == 0){
							a[b] += 1;
							c = c / prime[j];
							if (c%prime[j] != 0)b = b + 1;
						}
					}
					else break;

				}
			}

			product = 1;
			if (p[i] == true)product = 2;
			else{
				for (j = 0; j < b; j++){
					if (a[j] != 0)product = product*(a[j] + 1);
				}
			}
			if (i == l){
				z = product;
				q = i;
			}
			if (product > z){
				z = product;
				q = i;
			}
		}
		cout << "Between " << l << " and " << u << ", " << q << " has a maximum of " << z << " divisors" << "\n";

	}
	return 0;
}


