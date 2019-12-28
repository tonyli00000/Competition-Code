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
		freopen("gymnastics.in", "r", stdin);
		freopen("gymnastics.out", "w", stdout);
	}
	int K, n;
	cin >> K >> n;
	vector<vector<int>>all(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < K; i++) {
		vector<int>a(n);
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				all[a[j]][a[k]]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (all[i][j] == K)ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}