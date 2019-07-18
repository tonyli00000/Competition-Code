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

using namespace std;

long long find(long x, long y) {
	long i, l = 2;
	long long k = 1;
	for (i = x; i > x-y; i--) {
		k *= i;
		if (k%l == 0 && l <= y) {
			k = k / l;
			l++;
		}
		if (k > 1000000007)k = k - 1000000007;
	}
	for (i = x - y; i > x - y - y; i--) {
		k *= i;
		if (k%l == 0 && l <= y) {
			k = k / l;
			l++;
		}
		if (k > 1000000007)k = k - 1000000007;
	}
}
int main()
{
	long t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		long x;
		long long sum = 0;
		cin >> x;
		for (i = 1; i <= x / 2; i++) {
			sum += find(x, i);
		}
	}
	return 0;
}
