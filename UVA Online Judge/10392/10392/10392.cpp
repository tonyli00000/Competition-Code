#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 10000000
using namespace std;
long long i, j, k, a, b, c, prime[MAXN], top, i2, q;
bool p[MAXN];
int main()
{
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	top = 1;
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
	while ((cin >> a) && (a >= 0))
	{
		b = a;
			q = 0;
			for (i = 0; i < top; i++)
			{
				while (a%prime[i] == 0){
					a = a / prime[i];
					cout << "    " << prime[i] << "\n";
				}
				if (a == 1){
					cout << "\n";
					break;
				}
				if ((i == top - 1) || (b < prime[i])){
					cout << "    " << a << "\n" << "\n";
					break;
				}
			}

		
	}
	return 0;
}


