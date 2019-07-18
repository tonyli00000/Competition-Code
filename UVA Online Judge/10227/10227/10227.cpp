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

bool heard[102][102];
int convert(string s) {
	int i, m = 1, n = 0;
	for (i = s.length() - 1; i >= 0; i--) {
		n += m*(s[i] - '0');
		m *= 10;
	}
	return n;
}

bool sameset(int x, int y,int tree) {
	int i;
	for (i = 1; i <= tree; i++) {
		if (heard[x][i] != heard[y][i])break;
	}
	if (i == tree + 1)return true;
	else return false;
}
int main()
{
	int t,i,j,k;
	cin >> t;
	string line;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		int m, n;
		bool used[102];
		for (i = 0; i < 101; i++) {
			used[i] = false;
		}
		cin >> m >> n;
		for (i = 0; i < 101; i++) {
			for (j = 0; j < 101; j++) {
				heard[i][j]=false;
			}
		}
		getline(cin, line);
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			ss << line;
			string sa, sb;
			ss >> sa >> sb;
			int x = convert(sa), y = convert(sb);
			heard[x][y] = true;
			//ct[x]++;
		}
		int c = 0;
		for (i = 1; i <= m; i++) {
			bool st = used[i];
			for (j = i + 1; j <= m; j++) {
					if (!sameset(i, j, n));
					else {
						used[i] = true;
						used[j] = true;
					}
			}
			if (used[i] == false)c++;
			if (st != used[i])c++;
		}
		cout << c << "\n";
	}
	return 0;
}
