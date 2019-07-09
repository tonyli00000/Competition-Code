#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 10000000
using namespace std;
long long i2, top, f,prime[MAXN], i, j, k, x, y, b, a[MAXN];
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
	while (cin >> x){
		k = x;
		//for (i = 0; i <= b; i++)a[i] = 0;
		b = 0;
		y = 1;
		f = 1;
		for (j = 0; j < top; j++){
			if (x % prime[j] == 0)break;
			if (prime[j]>sqrt(x)){
				f = 0;
				break;
			}
		}
		for (i = 0; ((i <top)&&(x>1)&&(f==1)); i ++){
				while (x%prime[i]==0){
					a[i] += 1;
					x = x / prime[i];
				}
		}
		if (x > 1)y = 2;
		for (j = 0; j <= i; j++){
			if ((a[j] != 0)&&(j!=0)){
				y = y*(a[j] + 1);
			}
			if (a[j] != 0)a[j] = 0;
		}
		if ((f == 0)&&(k!=1))y = 2;
		if (y == 0)y = 1;
		if (k == 0)y = 0;
		cout << y<<"\n";
	}

	return 0;
}
