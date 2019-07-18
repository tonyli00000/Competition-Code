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

long long max(long long x, long long y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	long long t,i,j,k=0,m;
	while (cin >> t) {
		m = -1000000000000000009;
		int n[30],p;
		for (i = 0; i < t; i++) {
			cin >> n[i];
		}
		for (i = 0; i < t; i++) {
			long long q = n[i];
			for (j = i + 1; j < t; j++) {
				m = max(q*n[j], m);
				q = q*n[j];
			}
		}
		cout << "Case #" << ++k << ": The maximum product is ";
		cout << m << ".\n\n";
	}
	return 0;
}
