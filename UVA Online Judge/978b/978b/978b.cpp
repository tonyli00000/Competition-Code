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
	long t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		long x, y, z;
		cin >> x >> y >> z;
		multiset<long>green;
		multiset<long>blue;
		for (i = 0; i < y; i++) {
			cin >> j;
			green.insert(j);
		}
		for (i = 0; i < z; i++) {
			cin >> j;
			blue.insert(j);
		}
		while (!blue.empty() && !green.empty()) {
			multiset<long>::reverse_iterator it, p;
			int l[100002][2];
			for (i = 0; i < x; i++) {
				if (blue.empty() || green.empty())break;
				auto it = green.end();
				it--;
				auto p = blue.end();
				p--;
				l[i][0] = *it;
				l[i][1] = *p;
				green.erase(it);
				blue.erase(p);
			}
			for (j = 0; j <= i; j++) {
				if (l[j][0]>l[j][1]) {
					//green.erase(l[j][0]);
					green.insert(l[j][0] - l[j][1]);
					//blue.erase(l[j][1]);
				}
				else {
					if (l[j][0]<l[j][1]) {
						//green.erase(l[j][0]);
						blue.insert(l[j][1] - l[j][0]);
						//blue.erase(l[j][1]);
					}
					//else {
						//green.erase(l[j][0]);
						//blue.erase(l[j][1]);
					
				}
			}
		}
		if (green.empty() && blue.empty())cout << "green and blue died\n";
		else {
			if (green.empty()) {
				cout << "green wins\n";
				for (auto r = blue.rbegin(); r != blue.rend(); r++) {
					cout << *r << "\n";
				}
			}
			else {
				cout << "blue wins\n";
				for (auto r = green.rbegin(); r != green.rend(); r++) {
					cout << *r << "\n";
				}
			}
		}
	}
	return 0;
}
