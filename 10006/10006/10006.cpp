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
	long carmichael[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361 };
	int m = 16;
	int i;
	long n;
	while (cin >> n && n != 0) {
		for (i = 0; i < m; i++)
			if (carmichael[i] == n) {
				cout << "The number " << n << " is a Carmichael number.\n";
				break;
			}
		if (i == m) cout << n << " is normal.\n";
	}
	return 0;

}