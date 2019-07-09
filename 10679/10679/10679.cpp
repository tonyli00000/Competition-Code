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
	long t, i, j, k,l;
	cin >> t;
	for (k = 0; k < t; k++) {
		vector<string> sa[1002];
		string line,p;
		cin >> line;
		for (i = 0; i < line.length(); i++) {
			for (j = 0; j < line.length() - 1; j++) {
				string a = "";
				for (int m = 0; m <= i; m++) {
					a += line[m];
				}
				sa[i].push_back(a);
			}
		}
		int m;
		cin >> m;
		for (j = 0; j < m; j++) {
			cin >> p;
			int a;
			for (i = 0; i < sa[p.length() - 1].size(); i++) {
				if (sa[p.length() - 1][i] == p)break;
			}
			if (i != sa[p.length()-1].size())cout << "y\n";
			else cout << "n\n";
		}
	}
	return 0;
}
