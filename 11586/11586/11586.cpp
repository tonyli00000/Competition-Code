#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string line;
int i, j, k;
int main()
{
	int t;
	cin >> t;
	getline(cin, line);
	for (k = 0; k < t; k++) {
		line = "";
		getline(cin, line);
		if (line == "")cout << "LOOP\n";
		else {
			for (i = 0; i < line.length(); i++) {
				if (line[i] == ' ') {
					line.erase(i, 1);
					i = 0;
				}
			}
			for (i = 1; i < line.length() - 1; i += 2) {
				if (line[i + 2] != line[i]) {
					char temp = line[i + 2];
					line[i + 2] = line[i + 1];
					line[i + 1] = temp;
				}
				else if (line[i] == line[i + 1])break;
			}
				if (i != line.length() - 1 || line.length() == 2)cout << "NO LOOP\n";
				else {
					if (line[line.length() - 1] != line[0])cout << "LOOP\n";
					else cout << "NO LOOP\n";
				}
			
		}
	}
	return 0;
}
