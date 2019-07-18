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
bool flag;
string r;
bool ispal(string s) {
	int i,p=s.length();
	for (i = 0; i < p; i++) {
		if (s[i] != s[p - 1 - i])break;
	}
	if (i == p)return true;
	else return false;
}

void find(string s,string p,int ct) {
	if (ispal(s)&&!flag) {
		flag = true;
		r = s;
		return;
	}
	else{
		s = p;
		int i;
		string temp = s,l=s;
		
			temp.erase(ct, 1);
			find(temp,s,ct+1);
			temp = l;
		
	}
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	string line,temp;
	for (k = 0; k < t; k++) {
		cin >> line;
		temp = line;
		int c = 0;
		flag = false;
		int ct = 0;
		while (ct < line.length()) {
			if (ispal(temp))break;
			else {
				
			}
		}
		cout << temp.length() << "\n";
	}
	return 0;
}
