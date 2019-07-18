#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	int t, i, j, k;
	cin >> t;
	for (i = 0; i < t; i++) {
		cout << "Case " << i + 1 << ": ";
		int a, b, c;
		cin >> a >> b >> c;
		if (a > 20 || b > 20 || c > 20)cout << "bad\n";
		else cout << "good\n";
	}
	return 0;
}
