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

string rev(string line) {
	int i;
	for (i = 0; i < line.length() / 2; i++) {
		char temp = line[i];
		line[i] = line[line.length() - 1 - i];
		line[line.length() - 1 - i] = temp;
	}
	return line;
}
int main()
{
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		ss << line;
		string l;
		bool flag = true;
		while (ss >> l) {
			if (!flag)cout << " ";
			else {
				flag = false;
			}
			cout << rev(l);
		}
		cout << "\n";
	}
	return 0;
}
