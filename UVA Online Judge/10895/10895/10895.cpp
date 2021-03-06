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

using namespace std;

int main()
{
	int m, n, i, j, k;
	while (cin >> m >> n) {
		map <int, int> matrix[10002];
		map <int, int> trans[10002];
		for (i = 0; i < m; i++) {
			int t, p[1002];
			cin >> t;
			for (j = 0; j < t; j++) {
				cin >> p[j];
			}
			for (j = 0; j < t; j++) {
				int x;
				cin >> x;
				matrix[i][p[j]] = x;
			}
		}
		map <int, int>::iterator it;
		for (i = 0; i < m; i++) {
			for (it = matrix[i].begin(); it != matrix[i].end(); it++) {
				trans[it->first][i] = matrix[i][it->first];
			}
		}
		cout << n << " " << m << "\n";
		for (i = 1; i < n + 1; i++) {
			int l = trans[i].size(), ct = 0;
			if(l!=0)cout << l << " ";
			if (l == 0)cout << "0\n\n";
			for (it = trans[i].begin(); it != trans[i].end(); ++it) {
				cout << it->first + 1;
				if (ct == l - 1) {
					cout << "\n";
					break;
				}
				else cout << " ";
				ct++;
			}
			ct = 0;
			for (it = trans[i].begin(); it != trans[i].end(); ++it) {
				cout << it->second;
				if (ct == l - 1) {
					cout << "\n";
					break;
				}
				else cout << " ";
				ct++;
			}
		}
	}
	return 0;
}
