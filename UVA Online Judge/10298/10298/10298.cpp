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
	while (getline(cin, line) && line != ".") {
		map<char, long>l;
		l[line[0]]++;
		char prev = line[0];
		long max = 0, len = line.length();
		bool got = true;
		long i, j;
		for (i = 1; i < line.length(); i++) {
			if (len%i != 0)continue;
			for (long j = i; j < len; j++)
				if (line[j] != line[j%i]) {
					got = false;
					break;
				}
			if (got)break;
			got = true;
		}
		if (got)cout << len / i << "\n";
		else cout << len << "\n";

	}
	return 0;
}
