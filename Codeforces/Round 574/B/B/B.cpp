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

#define INF 10000000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int t = i * (i + 1) / 2;
		if (t - (n - i) == k) {
			cout << n - i << "\n";
			exit(0);
		}
	}
	return 0;
}