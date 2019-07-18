#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXP 12000
using namespace std;
int prime[4000];
bool p[12001];
int main()
{
	long long i, i2, j;
	int top;
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
	int pos = 0;
	int n;
	int sum = 0, con=0, p = pos;
	while (cin >> n && n != 0) {
		con = 0;
		pos = 0;
		while (prime[pos] <= n && pos<4000) {
			p = pos;
			while (sum < n) {
				sum = sum + prime[p];
				p++;
			}
			if (sum == n)con++;
			pos++;
			sum = 0;
		}
		cout << con << "\n";
	}
	return 0;
}
