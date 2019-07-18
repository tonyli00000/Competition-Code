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

long long sti(string s) {
	int i;
	long long sum = 0, m = 1;
	for (i = s.length() - 1; i >= 0;i--){
		sum += m*(s[i] - '0');
		m *= 10;
	}
	return sum;
}
int main()
{
	int t, i, j, k;
	string line;
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> line;
		cout << "Case " << k + 1 << ": ";
		i = 0;
		char c;
		bool flag = true;
		string n = "";
		while (i < line.length()) {
			if ('0' <= line[i] && line[i] <= '9')n += line[i];
			else {
				if (flag) {
					c = line[i];
					flag = false;
				}
				else {
					for (j = 0; j < sti(n); j++) {
						cout << c;
					}
					c = line[i];
					n = "";
				}
			}
			i++;
		}
		for (j = 0; j < sti(n); j++) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
