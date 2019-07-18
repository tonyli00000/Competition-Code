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

long long i, j, k;
int main()
{
	long long n;
	cin >> n;
	while (n--) {
		long long l, m, ct=0, sum = 0;
		cin >> l >> m;
		l *= 100;
		queue<pair<long long,long long>>left, right;
		for (i = 0; i < m; i++) {
			long long x;
			string y;
			cin >> x >> y;
			if (y == "left")left.push(make_pair(x,i));
			else right.push(make_pair(x,i));
		}
		bool L = true;
		while (!left.empty() || !right.empty()) {
			if (L) {
				if (left.empty()) {
					ct++;
					L = false;
					continue;
				}
				while (!left.empty() && sum + left.front().first <= l) {
					if (!right.empty() && left.front().second > right.front().second) {
						break;
					}
					else {
						sum += left.front().first;
						left.pop();
					}
				}
				sum = 0;
				L = false;
				ct++;
			}
			else {
				while (!right.empty() && sum + right.front().first <= l) {
					if (!left.empty() && right.front().second > left.front().second) {
						break;
					}
					else {
						sum += right.front().first;
						right.pop();
					}
				}
				sum = 0;
				L = true;
				ct++;
			}
			
		}
		cout << ct << "\n";
	}
    return 0;
}

