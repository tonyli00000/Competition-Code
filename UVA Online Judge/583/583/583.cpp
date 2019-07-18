#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXP 47000
using namespace std;
long long i2, prime[20000], i, j, k, top;
bool p[47000];
int main()
{
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
	long long t = 0;
	while (cin >> t && t != 0) {
		cout << t << " = ";
		bool flag = false;
		if (t < 0 && t!=-1) {
			t = t*-1;
			cout << "-1 x ";
			flag = true;
		}
		long long l = sqrt(t), y = 0, r = t;
		if (t == 1)cout<<"\n";
		else {
			while (prime[y] < l && y < 19990) {
				if (t%prime[y] == 0) {
					t = t / prime[y];
					if (t == 1)cout << prime[y] << "\n";
					else cout << prime[y] << " x ";
				}
				else y++;

			}
			if (t == r && flag == false)cout << t << "\n";
			else
				if (t != 1)cout << t << '\n';
		}
	}
	return 0;
}
