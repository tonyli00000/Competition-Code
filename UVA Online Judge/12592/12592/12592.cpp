#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

map <string, string> slogan;
int main()
{
	int i, j, k, t;
	cin >> t;
	string line,line2;
	getline(cin, line);
	for (i = 0; i < t; i++) {
		getline(cin, line);
		getline(cin, line2);
		slogan[line] = line2;
	}
	cin >> t;
	getline(cin, line);
	for (i = 0; i < t; i++) {
		getline(cin, line);
		cout << slogan[line] << "\n";
	}
	return 0;
}
