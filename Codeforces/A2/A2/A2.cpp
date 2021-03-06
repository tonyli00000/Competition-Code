#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define INF 10000000
#define MOD 1000000007
using namespace std;

bool isValid(string s) {
	stack<char> operatorStack;
	bool ret = true;

	for (char &c : s) {
		if (c == '(') {
			operatorStack.push(c);
		}
		else if (c == ')') {
			if (operatorStack.empty() || operatorStack.top() != '(') {
				ret = false;
				break;
			}
			operatorStack.pop();
		}
	}
	if (!operatorStack.empty()) ret = false;
	return ret;
}

//-- TASK 1
void task1() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	cout << s << "\n";
}

//-- TASK 2
void task2() {
	int n, m;
	cin >> n >> m;
	string s = "";
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < x.size(); j++)
			s += 'x';
	}
	cout << s << "\n";
}

//-- TASK 3
void task3() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i < m; i++) {
		string x;
		cin >> x;
		if (x.length() > s.length())s = x;
	}
	cout << s << "\n";
}

//-- TASK 4
void task4() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	cout << s << "\n";
}

//-- TASK 5
void task5() {
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;
		if (c == 'w')s += "(";
		else s += ")";
	}
	if (isValid(s))cout << "x\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=30;i++){
		cout << "1 " << i << " p x c d o" << "\n";
	}
	return 0;
}