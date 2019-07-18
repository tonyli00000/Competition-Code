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
	string line;
	while (cin >> line && line != "0") {
		int a = 0, b = 0;
		for (int i = 0; i < line.length(); i += 2) {
			a += line[i] - '0';
		}
		for (int i = 1; i < line.length(); i += 2) {
			b += line[i] - '0';
		}
		if (abs(a - b) % 11 == 0)cout << line << " is a multiple of 11.\n";
		else cout << line << " is not a multiple of 11.\n";
	}
	return 0;
}
