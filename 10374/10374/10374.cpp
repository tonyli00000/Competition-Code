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
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		map<string, string>party;
		map<string, int>votes;
		int m, n;
		cin >> m;
		string line;
		getline(cin, line);
		for (i = 0; i < m; i++) {
			getline(cin, line);
			string l = line;
			getline(cin, line);
			party[l] = line;
			votes[l] = 0;
		}
		cin >> n;
		getline(cin, line);
		int max = 0;
		string temp;
		bool flag = false;
		for (i = 0; i < n; i++) {
			getline(cin, line);
			votes[line]++;
			if (votes[line] == max)flag = true;
			if (votes[line] > max) {
				max = votes[line];
				temp = line;
				flag = false;
			}
			
		}
		if (flag)cout << "tie\n";
		else cout << party[temp] << "\n";
	}
	return 0;
}
