#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int num[105],o;
int xGCD(int a, int b, int &x, int &y) {
	if (b == 0) {
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
	int t,i,j,k,p;
	string line;
	bool flag = false;
	cin >> t;
	getline(cin, line);
	for (i = 0; i < t; i++) {
		for (j = 0; j < 105; j++)num[j] = 0;
		int count = 0;
		getline(cin, line);
		p = 0;
		flag = false;
		for (j = 0; j < line.length(); j++) {
			if (line[j] != ' ') {
				for (k = j; k < line.length(); k++) {
					if (line[k] == ' ') {
						o = k;
						break;
					}
				}
				if (k == line.length()) {
					flag = true;
					break;
				}
				int factor = 1;
				for (k = o - 1; k >= j; k--) {
					p = p + factor*(line[k] - '0');
					factor = factor * 10;
				}
				line.erase(0, o+1);
				num[count] = p;
				p = 0;
				count++;
				j = -1;
			}
		}
		int factor = 1;
		if (flag) {
			for (j = 0; j < line.length(); j++) {
				if (line[j] == ' ') {
					line.erase(0, 1);
					j = -1;
				}
			}
			for (k = line.length() - 1; k >= 0; k--) {
				p = p + factor*(line[k] - '0');
				factor = factor * 10;
			}
			num[count] = p;
			count++;
		}
		
		int gcd = 0;
		for (j = 0; j <= count-1; j++) {
			for (k = j + 1; k <= count-1; k++) {
				int u = 0, i = 0;
				if (xGCD(num[j], num[k], u, i) > gcd)gcd = xGCD(num[j], num[k], u, i);
			}
		}
		cout << gcd << "\n";
	}
	return 0;
}
