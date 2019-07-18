#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string line;
int i, j, k;

int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int max(int x, int y) {
	if (x < y)return y;
	else return x;
}
int main()
{
	int p = 0;
	while (getline(cin, line) && line.length() != 0 ) {
		if (cin.bad());
		else {
			p++;
			cout << "Case " << p << ":\n";
			int t;
			cin >> t;
			for (i = 0; i < t; i++) {
				int m, n;
				cin >> m >> n;
				for (j = min(m, n); j <= max(m, n); j++) {
					if (line[j] != line[min(m, n)])break;
				}
				if (m == n)cout << "Yes\n";
				else {
					if (j==1+max(m,n))cout << "Yes\n";
					else cout << "No\n";
				}
			}
			getline(cin, line);
		}
	}
	return 0;
}
