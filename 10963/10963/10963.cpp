#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k;
int main()
{
	int t;
	cin >> t;
	for (i = 0; i < t; i++) {
		if (i != 0)cout << "\n";
		int m;
		cin >> m;
		bool flag = true;
		int c, d;
		cin >> c >> d;
		int p = abs(c - d);
		for (j = 1; j < m; j++) {
			int a, b;
			cin >> a >> b;
			if (abs(a - b) != p)flag = false;
		}
		if (flag)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
