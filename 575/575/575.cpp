#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string s;
long long n, c;

int main()
{
	int i, k, t;

	while (cin >> s, s != "0") {
		n = 0;
		t = 1;
		for (i = 0; i < s.length(); i++) {
			c = s[s.length() - 1 - i] - '0';
			t *= 2;
			n += c * (t - 1);
		}
		cout << n << "\n";
	}
	return 0;
}