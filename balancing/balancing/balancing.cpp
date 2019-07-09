/*
ID: tonyli21
PROG: balancing
LANG: C++
*/
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

int main()
{
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	long n,b;
	cin >> n>>b;
	vector<long>x;
	vector<long>y;
	for (int i = 0; i < n; i++) {
		long a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	long ans = n;
	for (long i = 0; i < n; i++) {
		for (long j = 0; j < n; j++) {
			long a = x[i] + 1, b = y[j] + 1, ct[5] = { 0,0,0,0 ,0};
			for (int k = 0; k < n; k++) {
				if (x[k] < a&&y[k]<b)ct[1]++;
				if (x[k]<a&&y[k]>b)ct[4]++;
				if (x[k] > a&&y[k] < b)ct[2]++;
				if (x[k] > a&&y[k]>b)ct[3]++;
			}
			ans = min(ans, max(max(ct[1], ct[2]), max(ct[3], ct[4])));
		}
	}
	cout << ans << "\n";
	return 0;
}


