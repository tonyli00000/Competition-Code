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
	string line;
	int i, j, k;
	while (getline(cin, line) && line != "e/o/i") {
		bool flag = false;
		int ct = 0, l = 0, a[3] = { 5,7,5 };
		for (i = 0; i < line.length(); i++) {
			if (line[i] == '/') {
				flag = false;
				if (a[l] != ct)break;
				ct = 0;
				l++;
			}
			else {
				if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i]=='y') {
					if (!flag) {
						flag = true;
						ct++;
					}
				}
				else {
					if (flag)flag = false;
				}

			}
		}
			if (i == line.length() && ct==5)cout << "Y\n";
			else cout << l + 1 << "\n";
	}
	return 0;
}
