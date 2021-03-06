#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

#define INF 10000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, m,sum=0;
	cin >> n >> m;
	vector<long long>x(n);
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		x[i] = a - b;
		sum += a;
	}
	sort(x.begin(), x.end());
	if (sum <= m)cout << 0 << "\n", exit(0);
	int ct = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum -= x[i];
		ct++;
		if (sum <= m)cout << ct << "\n", exit(0);
	}
	cout << -1 << "\n";
	return 0;
}