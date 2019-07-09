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
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, sum = 0, mean;
		vector<int>r;
		int median = 0;
		cin >> m;
		r.resize(m);
		int a[2] = { m / 2 - 1, m / 2 - 1 + m % 2 };
		for (i = 0; i < m; i++) {
			int x;
			cin >> x;
			sum += x;
			r[i] = x;
		}
		sort(r.begin(),r.end());
		median += r[a[0]] + r[a[1]];
		median = median/2;
		sum = 0;
		for (i = 0; i < m; i++) {
			sum += abs(median - r[i]);
		}
		cout << sum << "\n";
	}
	return 0;
}
