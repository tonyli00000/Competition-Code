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
#include <algorithm>

using namespace std;

int main()
{
	string line;
	int i, j, k,ct=0;
	while (getline(cin, line)) {
		bool first = false , second = false, third = true;
		int a=0, b=0, c=0, op,m=1;
		if (line[line.length() - 1] == '?')continue;
		for (i = line.length() - 1; i >= 0; i--) {
			if (line[i] == '=') {
				second = true, third = false;
				m = 1;
				continue;
			}
			if (line[i] == '+' || line[i] == '-') {
				op = line[i];
				first = true, second = false;
				m = 1;
				continue;
			}
			if (third) {
				c += (line[i] - '0')*m;
				m *= 10;
			}
			else {
				if (second) {
					b += (line[i] - '0')*m;
					m *= 10;
				}
				else {
					a += (line[i] - '0')*m;
					m *= 10;
				}
			}
		}
		if (op == '+') {
			if (a + b == c)ct++;
		}
		else {
			if (a - b == c)ct++;
		}
	}
	cout << ct << "\n";
	return 0;
}
