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

long long convert(string x, int base) {
	int i;
	long long ans = 0;
	for (i = x.length() - 1; i >= 0; i--) {
		ans += (x[i] - '0')*pow(base, (x.length() - 1 - i));
	}
	return ans;
}
int main()
{
	freopen("whatbase.in", "r", stdin);
	freopen("whatbase.out", "w", stdout);
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		string x, y;
		cin >> x >> y;
		int a = 10, b = 10;
		while (a <= 15000 && b <= 15000) {
			long long q = convert(x, a), w = convert(y, b);
			if (q < w)a++;
			else if (q>w)b++;
			else {
				cout << a << " " << b << "\n";
				break;
			}
		}
	}
	return 0;
}
