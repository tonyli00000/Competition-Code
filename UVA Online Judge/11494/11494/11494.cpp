#include <iostream>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x, y, m, n, i, j, k;
int main()
{
	while ((cin >> x >> y >> m >> n) && (x != 0) && (y != 0) && (m != 0) && (n != 0)){
		if ((x == m) && (y == n))cout << 0 << "\n";
		else{
			if ((abs(m - x) == abs(n - y)) || (x == m) || (y == n))cout << 1 << "\n";
			else cout << 2 << "\n";
		}
	}
	return 0;
}
