#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k,power[1000];
bool status[1000];
int main()
{
	int m, n, p,max,l=0;
	while (cin >> m >> n >> p) {
		if (m == 0 & n == 0 & p == 0)break;
		cout << "\n";
		bool flag = true;
		l++;
		cout << "Sequence " << l << "\n";
		max = 0;
		int total = 0;
		for (i = 0; i < 1000; i++)status[i] = false;
		for (i = 0; i < m; i++)cin >> power[i];
		for (i = 0; i < n; i++) {
			int o;
			cin >> o;
			if (status[o - 1] == false) {
				total += power[o - 1];
				status[o - 1] = true;
			}
			else {
				total -= power[o - 1];
				status[o - 1] = false;
			}
			if (total > p) {
				cout << "Fuse was blown.\n";
				flag = false;
				break;
			}
			if (total > max)max = total;
		}
		if (flag) {
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << max << " amperes\n";
		}
	}
	return 0;
}
