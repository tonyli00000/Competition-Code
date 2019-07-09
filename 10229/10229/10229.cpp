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

int main()
{
	vector<long>fib;
	fib.push_back(0);
	fib.push_back(1);
	fib.push_back(1);
	int t = 2;
	while (t <= 2147483648){
		fib.push_back(fib[t] + fib[t - 1]);
		t++;
	}
	long n;
	int m;
	while (cin >> n >> m){
		long long k = pow(2, m);
		cout << fib[n - 1] % k << "\n";
	}
	return 0;
}
