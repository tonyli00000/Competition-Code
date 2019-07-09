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
#define MAXP 20000000
using namespace std;

bool p[20000003];
long long prime[20000003];
vector<long long>twin;
vector<long long>w;
int main()
{
	long long i, j, k, n,top=1,i2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	prime[0] = 2;
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
	while (cin >> n) {
		if (n <= twin.size());
		else {
			if (twin.empty()) {
				i = 0;
				while (twin.size() < n) {
					if (prime[i + 1] - prime[i] == 2) {
						twin.push_back(prime[i]);
						w.push_back(i+1);
					}
					i++;
				}
			}
			else {
				j = w[twin.size() - 1];
				while (twin.size() < n) {
					if (prime[j + 1] - prime[j] == 2) {
						twin.push_back(prime[j]);
						w.push_back(j+1);
					}
					j++;
				}
			}
		}
		cout << "(" << twin[n - 1] << ", " << twin[n - 1] + 2 << ")\n";
	}
	return 0;
}
