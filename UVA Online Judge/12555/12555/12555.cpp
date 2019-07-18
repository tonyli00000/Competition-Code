#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int x, y, t;
long double w;

int main()
{
	string s1, s2, line;
	int j;
	char ch;
	bool flag;

	cin >> t;
	getline(cin, line);
	for (int q = 1; q <= t; q++) {
		getline(cin, line);
		int x = 0, y = 0;
		flag = true;
		for (j = 0; j < line.length(); j++) {
			ch = line[j];
			if ((ch >= '0') && (ch <= '9')) {
				if (flag) x = x * 10 + (ch - '0');
				else y = y * 10 + (ch - '0');
			}
			else flag = false;
		}
		cout << "Case " << q << ": " << x * 0.5 + y * 0.05<< "\n";
	}
	return 0;
}