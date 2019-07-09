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

vector<string> x;
vector<string> y;
int c[1005][1005];
int LCSLength(int m, int n) {
	int i, j;

	for (i = 0; i <= m; ++i)
		c[i][0] = 0;

	for (j = 0; j <= n; ++j)
		c[0][j] = 0;

	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[m][n];
}
int main()
{
	string a, b;
	int t = 0;
	while (getline(cin, a)) {
		getline(cin, b);
		cout << setw(2) << setiosflags(ios::right) << ++t << ". ";
		if (a == "" || b == "")cout<<"Blank!\n";
		else {
			for (int i = 0; i < a.length(); i++) {
				if (!isupper(a[i]) && !islower(a[i]) && !isdigit(a[i])) a[i] = ' ';
			}
			for (int i = 0; i < b.length(); i++) {
				if (!isupper(b[i]) && !islower(b[i]) && !isdigit(b[i])) b[i] = ' ';
			}
			int w1 = 0, w2 = 0;
			x.clear();
			y.clear();
			string l;
			stringstream ss(a);
			while (ss >> l) {
				x.push_back(l);
				w1++;
			}
			string p;
			stringstream sss(b);
			while (sss >> p) {
				y.push_back(p);
				w2++;
			}
			cout << "Length of longest match: " << LCSLength(w1, w2) << "\n";
		}
	}
	return 0;
}
