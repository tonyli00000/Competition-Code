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

int main()
{
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		string line;
		cin >> line;
		int c = 1;
		while (c < line.length()) {
			while (line.length() % c != 0)c++;
			string temp = "";
			for (j = 0; j < c; j++) {
				temp += line[j];
			}
			for (i = 0; i < line.length(); i+=c) {
				string tmp = "";
				for (j = i; j < c + i; j++) {
					tmp += line[j];
				}
				if (temp != tmp)break;
			}
			if (i == line.length())break;
			else c++;
		}
		cout << c << "\n";
	}
	return 0;
}
