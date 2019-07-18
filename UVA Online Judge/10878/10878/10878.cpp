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
	while (getline(cin,line)) {
		if (line[0] != '|') continue;
		char c = 128;
		char sum = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ')c >>= 1;
			else {
				if (line[i] == 'o') {
					sum += c;
					c >>= 1;
				}
			}
		}
		cout << sum;
	}
	return 0;
}