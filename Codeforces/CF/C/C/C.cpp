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
#define INF 10000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		long long change = x*n;
		long long a = n/2, b = n-a-1;
		if (y >0) {
			change += (n * (n - 1) / 2) * y;
		}
		else {
			change += (((a*(a + 1)/2 + b * (b + 1)/2) * y));
		}
		sum += change;
	}
	cout << fixed << setprecision(12) << sum * 1.0 / n << "\n";
	return 0;
}