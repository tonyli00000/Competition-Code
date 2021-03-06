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
	long long n,i,j,k;
	while (cin >> n && n != 0) {
		if (n == 1) {
			long long t;
			cin >> t;
			cout << t << "\n";
		}
		else {
			priority_queue<long, vector<long>, greater<long>> p;
			long long t, sum = 0;
			for (i = 0; i < n; i++) {
				cin >> t;
				p.push(t);
			}
			while (p.size() > 1) {
				long long a, b;
				a = p.top();
				p.pop();
				b = p.top();
				p.pop();
				p.push(a + b);
				sum += a + b;
			}
			cout << sum << "\n";
		}
	}
	return 0;
}
