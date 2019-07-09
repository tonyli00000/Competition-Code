#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

long long b[2];
long long i, j, k, x, y, gcf = 0;

int xGCD(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
	while (cin >> x >> y) {
		bool flag = false;
		long long positive = 0;
		if (x == 0 || y == 0) {
			flag = true;
			if (x == 0)positive = y;
			else positive = x;
			cout << 0 << " " << 1 << " " << positive << "\n";
		}
		else {
			long long a = 0, c = 0;
			long long q = x, w = y,gcd=0;
			int u, i;
			gcd = xGCD(x, y, u, i);
			cout << u << " " << i << " " << gcd << "\n";
		}
	}
	return 0;
}