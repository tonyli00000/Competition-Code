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

long long survivor(long long n, long long m) {
	long long i, s;
	for (s = 0, i = 1; i <= n; i++) s = (s + m) % i;
	return (s + 1);
}
int main()
{
	int t;
	cin >> t;
	long long i, j, k;
	for (k = 0; k < t; k++) {
		long long m, n;
		cin >> m >> n;
		cout << "Case "<<k+1<<": "<<survivor(m,n)<<"\n";
	}
	return 0;
}
