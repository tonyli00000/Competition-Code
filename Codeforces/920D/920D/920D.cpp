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
	#define MAXN 5005
	using namespace std;
	vector<vector<bool>>dp(MAXN, vector<bool>(MAXN, false));
	vector<vector<int>>last(MAXN, vector<int>(MAXN,0));

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		int n, k;
		long long v,sum=0;
		cin >> n >> k >> v;
		vector<long long>x(n+1),y(n+1);
		bool found = false;

		for (int i = 0; i < n; i++) {
			cin >> x[i]; sum += x[i];
			y[i] = x[i] % k;
			if (x[i] == v)found = true;
		}
		if (sum < v)cout << "NO\n",exit(0);
		if (found)cout << "YES\n", exit(0);
		dp[0][0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				if (dp[i][j]) {
					dp[i + 1][j] = true;
					dp[i + 1][(j + y[i]) % k] = true;
				}
			}
		}
		if (!dp[n][v%k])cout << "NO\n", exit(0);
		cout << "YES\n";
		int i = n;
		vector<bool>used(n+1, false);
		int p = v % k;
		for (int i = n; i; i--) {
			if (dp[i-1][p])continue;
			used[i-1] = true;
			p = p - x[i-1]; p %= k; p += k; p %= k;
		}
		int a = -1, b = -1;
		for (int i = 0; i < n; i++) {
			if (used[i]) {
				if (a == -1) a = i;
				else {
					int ct = (x[i] + k - 1) / k;
					if (ct > 0) {
						cout << ct << " " << i+1 << " " << a+1 << "\n";
						x[a] += x[i]; x[i] = 0;
					}
				}
			}
			else {
				if (b == -1)b = i;
				else {
					int ct = (x[i] + k - 1) / k;
					if (ct > 0) {
						cout << ct << " " << i+1 << " " << b+1 << "\n";
						x[b] += x[i]; x[i] = 0;
					}
				}
			}
		}
		if (b == -1) b = (a == 0);
		if (a == -1)a = (b == 0);
		int ct = (v - x[a]) / k;
		a++; b++;
		if (ct > 0)cout << ct << " " << b << " " << a << "\n";
		if (ct < 0)cout << -ct << " " << a << " " << b << "\n";
		return 0;
	}