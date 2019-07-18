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


long solve(int a, int b) {
	long long sum = 1;
	//int n[102];
	int l = 1;
	int i, j, k,ct=0;
	for (i = a; ct != b; i--) {
		sum *= i;
		while (l <= b && sum%l == 0) {
			sum = sum / l;
			l++;
		}
		ct++;
	}
	return sum;
}
int main()
{
	int i, j, k;
	long a, b, c;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)break;
		long p;
		if (b>a / 2) {
			p = solve(a, a - b);
		}
		else {
			p = solve(a, b);
		}
		cout << a << " things taken " << b << " at a time is " << p << " exactly.\n";
	}
	return 0;
}
