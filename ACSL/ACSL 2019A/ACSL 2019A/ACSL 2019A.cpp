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
#define int long long
	int test = 5;
	while (test--) {
		int n, m;
		cin >> n >> m;
		vector<int>digits;
		while (n) {
			digits.push_back(n % 10);
			n /= 10;
		}
		reverse(digits.begin(), digits.end());
		int t = digits.size(), ret = 0;
		for (int i = 0; i <= t - m; i++) {
			int curr = 0, mult = 1;
			for (int j = i + m - 1; j >= i; j--) {
				curr += mult * digits[j];
				mult *= 10;
			}
			ret += curr;
		}
		cout << ret << "\n";
	}
	return 0;
}