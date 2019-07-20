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
#define MOD 998244353
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n, m;
	cin >> n >> m;
	int ret = 1;
	for (int i = 0; i < n + m; i++) {
		ret *= 2;
		ret %= MOD;
	}
	cout << ret << "\n";
	return 0;
}