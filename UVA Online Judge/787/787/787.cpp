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

long long max(long long x, long long y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	long long n, i,ct=1;
	vector<long>m;
	while (cin >> i) {
		m.clear();
		ct = 1;
		m.push_back(i);
		while (cin >> n) {
			if (n != -999999) {
				m.push_back(n);
				ct++;
			}
			else {
				long long sum = 1, ans = 0;
				for (i = 0; i < ct; i++) {
					sum = m[i] * sum;
					ans = max(ans, sum);
				}
				cout << ans << "\n";
			}
		}
	}
	return 0;
}
