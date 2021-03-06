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

using namespace std;

int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int main()
{
	int t;
	long long i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		long long a, b, c;
		cin >> a >> b >> c;
		multiset <int> green;
		multiset <int> blue;
		for (i = 0; i < b; i++) {
			int n;
			cin >> n;
			green.insert(n);
		}
		for (i = 0; i < c; i++) {
			int n;
			cin >> n;
			blue.insert(n);
		}
		multiset <int>::reverse_iterator it;
		multiset <int>::reverse_iterator p;
		while (!green.empty() && !blue.empty()) {
			it = green.rbegin();
			p = blue.rbegin();
			if (*it == *p) {
				green.erase(*it);
				blue.erase(*p);
			}
			else {
				if (*it > *p) {
					green.insert(*it - *p);
					blue.erase(*p);
					green.erase(*it);
				}
				else {
					blue.erase(*p);
					green.erase(*it);
					blue.insert(*p-*it);
				}
			}
		}
		if (green.empty() && blue.empty()) {
			cout << "green and blue died\n";
		}
		else {
			if (green.empty()) {
				cout << "blue wins\n";
				for (it = blue.rbegin(); it != blue.rend(); it++) {
					cout << *it << "\n";
				}
			}
			else {
				cout << "green wins\n";
				for (it = green.rbegin(); it != green.rend(); it++) {
					cout << *it << "\n";
				}
			}
		}
	}
	return 0;
}
