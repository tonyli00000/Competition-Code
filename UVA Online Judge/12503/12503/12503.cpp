#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k;
string line;
int movement[105];
int main()
{
	int t;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m,s=0;
		cin >> m;
		getline(cin, line);
		for (i = 0; i < m; i++) {
			getline(cin, line);
			if (line == "LEFT")movement[i] = -1;
			else {
				if (line == "RIGHT")movement[i] = 1;
				else {
					if (line.length() == 9)movement[i] = movement[line[line.length() - 1] - '0' - 1];
					if (line.length() == 10)movement[i] = movement[(line[line.length() - 2] - '0') * 10 + line[line.length() - 1] - '0' - 1];
				}
			}
			s += movement[i];
		}
		cout << s << "\n";
	}
	return 0;
}
