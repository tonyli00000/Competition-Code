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
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		int group[120], first;
		int n;
		cin >> n;
		int ct = 0,ind=0;
		char prev;
		for (i = 0; i < n; i++) {
			char x;
			cin >> x;
			if (i == 0) {
				ct++;
				if (x == '#')first = 0;
				else first = 1;
			}
			else {
				if (prev != x) {
					group[ind] = ct;
					ct = 1;
					ind++;
				}
				else ct++;
			}
			prev = x;
		}
		group[ind] = ct;
		int sum = 0;
		if (first == 1) {
			for (i = 0; i <= ind; i = i + 2) {
				if (group[i] % 3 == 2) {
					sum += group[i] / 3 + 1;
				}
				if (group[i] % 3 == 0)sum += group[i] / 3;
				if (group[i] % 3 == 1) {
					sum += group[i] / 3 + 1;
					if (group[i + 1] == 1)group[i + 2]--;
				}
			}
		}
		else {
			for (i = 1; i <= ind; i = i + 2) {
				if (group[i] % 3 == 2) {
					sum += group[i] / 3 + 1;
				}
				if (group[i] % 3 == 0)sum += group[i] / 3;
				if (group[i] % 3 == 1) {
					sum += group[i] / 3 + 1;
					if (group[i + 1] == 1)group[i + 2]--;
				}
			}
		}
		cout << "Case " << k + 1 << ": "<<sum<<"\n";
	}
	return 0;
}
