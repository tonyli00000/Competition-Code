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

int main()
{
	long b, p, m,i,j,k;
	while (cin >> b >> p >> m) {
		int r,t;
		if (b < m)r = b;
		else r = b%m;
		t = r;
		if (t == 0)cout << 0 << "\n";
		else {
			for (i = 1; i < p; i++) {
				t = (t*r) % m;
			}
			cout << t << "\n";
		}
	}
	return 0;
}
