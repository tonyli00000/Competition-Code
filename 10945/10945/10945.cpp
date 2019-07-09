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
	while (getline(cin, line) && line != "DONE") {
		int i, j, k;
		for (i = 0; i < line.length(); i++) {
			if (line[i] == ' ' || line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == '?') {
				line.erase(i, 1);
				i--;
			}
			else if (line[i] <= 'a')line[i] += 'a' - 'A';
		}
		for (i = 0; i < line.length() / 2; i++) {
			if (line[i] != line[line.length() - 1 - i])break;
		}
		if (i == line.length() / 2)cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
	}
	return 0;
}
