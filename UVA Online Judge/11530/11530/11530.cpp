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

map<char, int> k;
int main()
{
	k['a'] = 1;
	k['b'] = 2;
	k['c'] = 3;
	k['d'] = 1;
	k['e'] = 2;
	k['f'] = 3;
	k['g'] = 1;
	k['h'] = 2;
	k['i'] = 3;
	k['j'] = 1;
	k['k'] = 2;
	k['l'] = 3;
	k['m'] = 1;
	k['n'] = 2;
	k['o'] = 3;
	k['p'] = 1;
	k['q'] = 2;
	k['r'] = 3;
	k['s'] = 4;
	k['t'] = 1;
	k['u'] = 2;
	k['v'] = 3;
	k['w'] = 1;
	k['x'] = 2;
	k['y'] = 3;
	k['z'] = 4;
	k[' '] = 1;
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	int i, j;
	for (i = 0; i < n; i++) {
		getline(cin, line);
		int s = 0;
		for (j = 0; j < line.length(); j++) {
			s += k[line[j]];
		}
		cout << "Case #" << i + 1 << ": " << s << "\n";
	}
	return 0;
}
