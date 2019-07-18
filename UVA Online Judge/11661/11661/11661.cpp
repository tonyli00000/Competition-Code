#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	long long n, i, j, k;
	char c;
	string line;
	while (cin >> n && n != 0) {
		long long ct=0,min=2000000;
		char p=' ';
		bool flag = true,b=false;
		for (i = 0; i < n; i++) {
			cin >> c;
			if (c == 'Z') {
				min = 0;
				getline(cin, line);
				b = true;
				break;
			}
			if (c == '.' && flag==false)ct++;
			if (c == p && flag==false)ct = 0;
			if (c != p && c!='.' && flag==false) {
				if (ct < min)min = ct;
				p = c;
				ct = 0;
			}
			
			if (flag && ((c == 'R') || (c == 'D'))) {
				p = c;
				flag = false;
			}
		}
		if (b)cout << 0 << "\n";
		else cout << min+1 << "\n";
	}
	return 0;
}
