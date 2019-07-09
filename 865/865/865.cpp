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

map<char, char> dict;

char cypher(char letter) {
	map<char, char>::iterator it;
	it = dict.find(letter);
	if (it == dict.end()) {
		return letter;
	}
	else {
		return it->second;
	}
}

int main() {
	bool flag = true;
	string line;
	getline(cin, line);

	while (getline(cin, line)) {
		if (line.length() == 0) {
			if (flag) {
				flag= false;
			}
			else {
				cout << "\n";
			}
			dict.clear();
			string before, after;
			getline(cin, before);
			getline(cin, after);
			cout << after << "\n";
			cout << before << "\n";
			for (int i = 0; i<before.length(); i++) {
				dict.insert(pair<char, char>(before[i], after[i]));
			}
		}
		else {
			for (int i = 0; i<line.length(); i++) {
				cout << cypher(line[i]);
			}
			cout << "\n";
		}
	}
	return 0;
}