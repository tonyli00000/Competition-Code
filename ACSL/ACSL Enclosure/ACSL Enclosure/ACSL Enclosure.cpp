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
int i, j, k;
bool balanced(string s) {
	stack<char> paren;
	for (char& c : s) {
		if (c == '+' || c == '-' || c == '/' || c == '*' || isdigit(c))continue;
		switch (c) {
		case '(':
		case '{':
		case '[': paren.push(c); break;
		case ')': 
			if (paren.empty() || paren.top() != '(') return false;
			else paren.pop(); break;
		case '}': 
			if (paren.empty() || paren.top() != '{') return false;
			else paren.pop(); break;
		case ']': 
			if (paren.empty() || paren.top() != '[') return false;
			else paren.pop(); break;
		default:; 
		}
	}
	return paren.empty();
}
char missing(string line){//Finds the missing brace
	map<char, int>ct;
	for (int i = 0; i < line.length(); i++) {
		ct[line[i]]++;
	}
	if (ct['{']>ct['}'])return '}';
	if (ct['(']>ct[')'])return ')';
	if (ct['[']>ct[']'])return ']';
	if (ct['}']>ct['{'])return '{';
	if (ct[')']>ct['('])return '(';
	if (ct[']']>ct['['])return '[';
}
bool isLeft(char c) {//Finds whether the left or the right brace is unmatched
	if (c == '{' || c == '(' || c == '[')return true;
	return false;
}
bool checkLeft(string line, int x) {//check whether there is only 1 number between parenthesis
	while (line[x] == ' ') 
		x--;
	if (line[x] == '{' || line[x] == '(' || line[x] == '[')return false;
	return true;
}
bool checkRight(string line, int x) {//check whether there is only 1 number between parenthesis
	while (line[x] == ' ') 
		x++;
	if (line[x] == ')' || line[x] == ']' || line[x] == '}')return false;
	return true;
}
int main()
{
	for (k = 0; k < 5; k++) {
		string line,original;
		getline(cin, line);
		for (i = 0; i < line.length(); i++)
			if (isdigit(line[i]))line[i] = ' ';
		balanced(line);
		char need = missing(line);
		original = line;
		vector<int>ans;
		bool left = isLeft(need);
		if (left) {
			for (i = 0; i < line.length()-1; i++) {
				char c = line[i];
				if (i == 0) {
					line.insert(0, 1, need);
					if (balanced(line))ans.push_back(i+1);
					line = original;
					continue;
				}
				if (line[i] == ' ' || line[i] == '[' || line[i] == '(') {
					if (line[i-1] == ' ') continue;
					if (!checkRight(line, i))continue;
					line.insert(i, 1, need);
					if (balanced(line))ans.push_back(i+1);
					line = original;
				}
			}
		}
		else {
			for (i = 0; i < line.length(); i++) {
				char c = line[i];
				if (i == 0) {
					line.insert(0, 1, need);
					if (balanced(line))ans.push_back(i + 1);
					line = original;
					continue;
				}
				if (line[i] == ' '||line[i]==']'||line[i]==')') {
					if (i+1<line.length()&&line[i+1] == ' ') continue;
					if (!checkLeft(line, i))continue;
					if (i == line.length() - 1)line += need;
					else line.insert(i+1, 1, need);
					if (balanced(line))ans.push_back(i + 2);
					line = original;
				}
			}
		}
		cout << ans[0];
		for (i = 1; i < ans.size(); i++) {
			cout << ", " << ans[i];
		}
		cout << "\n";
	}
	return 0;
}

