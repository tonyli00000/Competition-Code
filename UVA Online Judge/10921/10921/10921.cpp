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
	map<char, int> a;
	char b = 'A';
	int n = 2;
	int i, j, k;
	for (i = 0; i < 5; i++) {
		a[char(b)] = n;
		a[char(b + 1)] = n;
		a[char(b + 2)] = n;
		b += 3;
		n++;
	}
	a['P'] = 7;
	a['Q'] = 7;
	a['R'] = 7;
	a['S'] = 7;
	a['T'] = 8;
	a['U'] = 8;
	a['V'] = 8;
	a['W'] = 9;
	a['X'] = 9;
	a['Y'] = 9;
	a['Z'] = 9;
	string line;
	while (cin >> line) {
		for (i = 0; i < line.length(); i++) {
			if (line[i] == '1' || line[i] == '0' || line[i] == '-')cout << line[i];
			else cout << a[line[i]];
		}
		cout << "\n";
	}
	return 0;
}
