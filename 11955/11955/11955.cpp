#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string line;
long long binomial[52][52];

int choose(long long x, long long y) {
	long long i, j, k,result=1;
	int q = y;
	for (i = x; i > x - y; i--) {
		result = result*i;
		if (i%q == 0) {
			result = result / q;
			if (q - 1 > 0)q--;
		}
	}
	return result;
}
void bi() {
	long long i, j, k;
	binomial[1][1] = 1;
	binomial[1][2] = 1;
	for (i = 2; i < 51; i++) {
		for (j = 1; j <= i + 1; j++) {
			binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
		}
	}
}
int main()
{
	int t,i,j,k,exp;
	cin >> t;
	getline(cin, line);
	bi();
	for (k = 0; k < t; k++) {
		cout << "Case " << k + 1 << ": ";
		getline(cin, line);
		exp = 0;
		int factor = 1;
		for (i = line.length()-1; i >= 0; i--) {
			if (line[i] == '^')break;
			else {
				exp = factor*(line[i] - '0') + exp;
				factor = factor * 10;
			}
		}
		for (i = 0; i < line.length(); i++) {
			if (line[i]<'a' || line[i]>'z') {
				if (line[i] != '+') {
					line.erase(i, 1);
					i = -1;
				}
			}
		}
		string a="", b="";
		int p;
		for (i = 0; i < line.length(); i++)if (line[i] == '+')p = i;
		int pos = 0;
		while (pos < p) {
			a = a + line[pos];
			pos++;
		}
		pos = p + 1;
		while (pos < line.length()) {
			b = b + line[pos];
			pos++;
		}
		if (exp == 1)cout << a << "+" << b << "\n";
		else {
			for (i = 1; i <= exp; i++) {
				if (binomial[exp][i] != 1)cout << binomial[exp][i] << "*";
				if (i == exp)cout << a;
				else if (i == 1)cout << a << "^" << exp;
				else cout << a << "^" << exp + 1 - i;
				cout << "*";
				if (i != 1) {
					if (i == 2)cout << b;
					else cout << b << "^" << exp - (exp + 1 - i);
				}
				cout << "+";
			}
			cout << b << "^" << exp << "\n";
		}
	}
	return 0;
}
