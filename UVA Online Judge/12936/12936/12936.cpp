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

bool find(string line) {
	int i = 0;
	if (line.length() < 4 || line.length()%2==1)return false;
	while (i < line.length()) {
		if (line[i] == 'h' && line[i + 1] == 'e');
		else break;
		i += 2;
	}
	if (i == line.length())return true;
	else return false;
}
char min(char a, char b) {
	if (a < b)return a;
	else return b;
}

char max(char a, char b) {
	if (a > b)return a;
	else return b;
}
int main()
{
	string line;
	map<pair<string, string>, bool> con;
	int i, j, k;
	while (getline(cin, line)) {
		string a, b;
		for (i = 0; i < line.length(); i++) {
			if ('A' <= line[i] && line[i] <= 'Z') line[i]+='a'-'A';
			else {
				if ('a' <= line[i] && line[i] <= 'z');
				else line[i] = ' ';
			}
		}
		stringstream ss(line);
		ss >> a >> b;
		string l;
		if (con.find(make_pair(b,a)) != con.end()) {
			string temp = a;
			a = b;
			b = temp;
		}
		bool x = con[make_pair(a, b)],y=false;
		if (x == true) {
			while (ss >> l) {
				if (find(l)) {
					con[make_pair(a, b)] = true;
					y = true;
					break;
				}
			}
			con[make_pair(a, b)] = y;
		}
		else {
			while (ss >> l) {
				if (find(l)) {
					con[make_pair(a, b)] = true;
					break;
				}
			}
		}
	}
	int ct = 0, tot = 0;
	for (auto it = con.begin(); it != con.end(); it++) {
		if (it->second)ct++;
		tot++;
	}
	cout << rint(ct*1.0 / tot*100) << "%\n";
	return 0;
}
