#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string line;
int digit[110];

void div() {
	int i, j, k;
	int x = digit[line.length()-1];
	line.erase(line.length() - 1, 1);
	digit[line.length() - 1] = digit[line.length() - 1] - (5*x)%10;
	if (digit[line.length() - 1] < 0) {
		int pos = 1;
		while (digit[line.length() - pos] < 0) {
			digit[line.length() - pos - 1] -= 1;
			digit[line.length() - pos] = 10 - abs(digit[line.length() - pos]);
			pos++;
		}
	}
	digit[line.length() - 2] = digit[line.length() - 2] - (5 * x) / 10;
	if (digit[line.length() - 2] < 0) {
		int pos = 2;
		while (digit[line.length() - pos] < 0) {
			digit[line.length() - pos - 1] -= 1;
			digit[line.length() - pos] = 10 - abs(digit[line.length() - pos]);
			pos++;
		}
	}
}
int main()
{
	int i, j, k;
	while (getline(cin, line) && line != "0") {
		for (i = 0; i < 110; i++)digit[i] = 0;
		for (i = 0; i < line.length(); i++) {
			digit[i] = line[i] - '0';
		}
		while (line.length() > 3) {
			div();
		}
		int num = digit[0] * 100 + digit[1] * 10 + digit[2];
		if (num % 17 == 0)cout <<"1\n";
		else cout << "0\n";
	}
	return 0;
}
