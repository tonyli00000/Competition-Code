#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 1500
using namespace std;
int i, j, k, a, b, c, prime[MAXN], top, i2, q, s;
bool p[MAXN];
string y;
int main()
{
	prime[0] = 2;
	p[0] = false;
	p[1] = true;
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
	for (i = 4; i < MAXN; i += 2){
		p[i] = false;
	}
	while (getline(cin, y)){
		s = 0;
		c = y.length();
		for (i = 0; i < c; i++){
			if ((y[i] >= 'a') && (y[i] <= 'z'))s = s + y[i] - 'a' + 1;
			if ((y[i] >= 'A') && (y[i] <= 'Z'))s = s + y[i] - 'A' + 27;
		}
		if (p[s] == true)cout << "It is a prime word." << "\n";
		else cout << "It is not a prime word." << "\n";
	}
	return 0;
}
