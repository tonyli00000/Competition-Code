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
	long long int n, i, sum[100000], fib[100000];
	while (cin >> n && n>=0) {
		fib[0] = 0;
		fib[1] = 1;
		sum[0] = 1;
		for (i = 2; i <= n; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		for (i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + fib[i + 1];
		cout << sum[n] - fib[i] << " " << sum[n] << "\n";
	}
    return 0;
}

