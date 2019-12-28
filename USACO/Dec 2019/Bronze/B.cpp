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
		freopen("whereami.in", "r", stdin);
		freopen("whereami.out", "w", stdout);
	}
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		bool found = true;
		for (int j = 0; j <= n - i; j++) {
			string curr = s.substr(j, i);
			for (int k = 0; k <=n-i; k++) {
				if (k == j)continue;
				if (s.substr(k, i) == curr) {
					found = false;
					break;
				}
			}
		}
		if (found)cout << i << "\n", exit(0);
	}
	return 0;
}