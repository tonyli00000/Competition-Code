#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;
#define MAXN 30000			// total # of prime numbers
#define MAXP 70000		// highest number to test prime

long long prime[MAXN];
long long n, s, c;
long top;
bool p[MAXP];
int main()
{
	long long i, i2, j;
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
	long long x;
	while (cin >> x && x){
		bool negative=false;
		long long temp = x;
		if (x < 0){
			negative = true;
			temp *= -1;
		}
		map<long, int>res;
		for (int i = 0; i < top && temp>1; i++){
			while (temp%prime[i] == 0){
				res[i]++;
				temp /= prime[i];
			}
		}
		int a = 1;
		if (negative)a = 2;
		for (i = 35; i >= 1; i-=a){
			bool valid = true;
			for (auto it = res.begin(); it != res.end(); it++){
				if (it->second%i != 0){
					valid = false;
					break;
				}
			}
			if (valid){
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
