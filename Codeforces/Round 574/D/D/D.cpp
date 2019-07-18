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
	int n;
	cin >> n;
	map<int, int>ct;
	vector<string>a(n);
	vector<int>place(25, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ct[a[i].size()]++;
	}

	for (int i = 0; i < n; i++) {
		for (auto it : ct) {
			int x = it.first, y = it.second;
			for (int j = 0; j < a[i].size(); j++) {
				int p = j * 2;
				if (j > x)p = (j - x) + x * 2;
				place[p] += y * (a[i][a[i].size()-j-1] - '0');
				place[p] %= MOD;
			}
		}
		//ct[a[i].size()]--;
		for (auto it : ct) {
			int x = it.first, y = it.second;
			for (int j = 0; j < a[i].size(); j++) {
				int p = j * 2 + 1;
				if (j >= x)p = x * 2 + (j - x);
				place[p] += y * (a[i][a[i].size()-j-1] - '0');
				place[p] %= MOD;
			}
		}
		//ct[a[i].size()]++;
	}

	int ret = 0,curr=1;
	for (int i = 0; i < place.size(); i++) {
		int x = ((place[i]%MOD) * curr) % MOD;
		ret = (ret + x) % MOD;
		curr *= 10;
		curr %= MOD;
	}
	cout << ret << "\n";
	return 0;
}