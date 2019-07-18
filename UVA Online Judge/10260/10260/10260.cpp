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
	map<char, int>s;
	s['B'] = 1;
	s['F'] = 1;
	s['P'] = 1;
	s['V'] = 1;
	s['C'] = 2;
	s['G'] = 2;
	s['J'] = 2;
	s['K'] = 2;
	s['Q'] = 2;
	s['S'] = 2;
	s['X'] = 2;
	s['Z'] = 2;
	s['D'] = 3;
	s['T'] = 3;
	s['L'] = 4;
	s['M'] = 5;
	s['N'] = 5;
	s['R'] = 6;
	string word;
	while (cin >> word) {
		string out = "";
		for (int i = 0; i < word.length(); i++) {
			if (i != 0) {
				if (s.find(word[i - 1]) != s.end() && s.find(word[i]) != s.end()) {
					if (s[word[i - 1]] == s[word[i]])continue;
				}
			}
			if (s.find(word[i])==s.end())continue;
			else out += (s[word[i]]+'0');
		}
		cout << out << "\n";
	}
    return 0;
}

