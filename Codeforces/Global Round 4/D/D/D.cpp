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
	vector<int>primes;
	for (int i = 2; i <= 2005; i++) {
		bool found = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				found = false;
				break;
			}
		}
		if (found)primes.push_back(i);
	}
	int n;
	cin >> n;
	int target;
	for (auto it : primes) {
		if (it >= n) {
			target = it;
			break;
		}
	}
	cout << target << "\n";
	for (int i = 1; i < n; i++) {
		cout << i << " " << i + 1 << "\n";
	}
	cout << 1 << " " << n << "\n";
	target -= n;
	vector<bool>used(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (target == 0)break;
		if (used[i])continue;
		if (i + 2 <= n && !used[i + 2]) {
			cout << i << " " << i + 2 << "\n";
			target--;
			used[i] = true;
			used[i + 2] = true;
		}
	}
	return 0;
}