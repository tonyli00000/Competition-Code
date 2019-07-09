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
#include <algorithm>

using namespace std;

bool ispal(int n) {
	string pal = "";
	while (n) {
		pal += (n % 10 + '0');
		n /= 10;
	}
	int i;
	bool flag = true;
	for (i = 0; i < pal.length() / 2; i++) {
		if (pal[i] != pal[pal.length() - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string line;
		cin >> line;
		line.erase(2, 1);
		for (int i = 0; i < line.length(); i++)
			line[i] -= '0';
		int a = line[0] * 1000 + line[1] * 100 + line[2] * 10 + line[3];
		bool first = true;
		if (a % 100 == 59) {
			a = ((a / 100 + 1) % 24) * 100;
		}
		else a++;
		while(!ispal(a)){
			if (a % 100 == 59) {
				a = ((a / 100 + 1) % 24) * 100;
			}
			else a++;
		} 

		if (a / 100 == 0)cout << "00:";
		else {
			if (a / 100 < 10)cout << "0";
			cout << a / 100 << ":";
		}
		if (a % 100 == 0)cout << "00";
		else {
			if (a % 100 < 10)cout << "0";
			cout << a % 100;
		}
		cout << "\n";
	}
	return 0;
}
