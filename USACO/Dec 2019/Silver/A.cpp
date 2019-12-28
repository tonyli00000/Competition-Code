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

#define INF 1000000000
#define MOD 1000000007
using namespace std;

#define ALL(a) a.begin(),a.end()

int main()
{
#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("moobuzz.in", "r", stdin);
		freopen("moobuzz.out", "w", stdout);
	}
	int n;
	cin >> n;
	int l = 1, r = 1e12;
	while (l <= r) {
		int mid = (l + r) / 2;
		int ct = mid - mid / 3 - mid / 5 + mid / 15;
		if (ct == n) {
			if (mid % 3 == 0 || mid % 5 == 0)r = mid - 1;
			else cout << mid << "\n", exit(0);
		}
		else {
			if (ct < n)l = mid + 1;
			else r = mid - 1;
		}
	}

	return 0;
}