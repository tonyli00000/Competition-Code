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
	string s, a, b;
	char m[3000];
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';
	while (cin >> s) {
		a = b = "";
		int len = s.size();
		for (int i = len - 1; i >= 0; i--)
		{
			a += s[i];
			b += m[s[i]];
		}
		if (s == a && s == b)
			cout << s << " -- is a mirrored palindrome." << "\n\n";
		else if (s == a && s != b)
			cout << s << " -- is a regular palindrome." << "\n\n";
		else if (s != a && s == b)
			cout << s << " -- is a mirrored string." <<"\n\n";
		else
			cout << s << " -- is not a palindrome." << "\n\n";
	}
	return 0;
}

