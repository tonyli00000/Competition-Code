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
long s[75][75];
int main()
{
	int t;
	cin >> t;
	int i, j, k,l;
	for (l = 0; l < t; l++) {
		int x, y, z;
		cin >> x >> y >> z;
		for (i = 0; i < 71; i++) {
			for (j = 0; j < 71; j++) {
				s[i][j] = 0;
			}
		}
		s[0][0] = 1;
		for (i = 1; i <= x; i++) {
			for (j = z; j <= y; j++) {
				if ((y - j)*1.0 / (x - i) < z)break;
				for (k = j; k >= z; k--) {
					s[i][j] += s[i - 1][j - k];
				}
			}
		}
		cout << s[x][y] << "\n";
	}
	return 0;
}
