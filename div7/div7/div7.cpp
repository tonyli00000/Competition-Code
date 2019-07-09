/*
ID: tonyli21
PROG: angry
LANG: C++11
*/
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
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	long n,sum=0;
	cin >> n;
	vector<long long>x, y;
	x.resize(7,10000000000000);
	y.resize(7);
	x[0] = 0;
	long long a=0;
	for (long long i = 1; i <= n;i++) {
		long long b;
		cin >> b;
		a += b;
		a = a % 7;
		x[a]=min(a,i);
		y[a]=(i);
	}
	long long ans = -1;
	for (long long i = 0; i < 7; i++) {
		if (x[i] <= n) {
			ans = max(ans, x[i] - y[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}
