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
#include <cassert>
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 998244353

#define ALL(a) a.begin(),a.end()
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long

	vector<int>fact((3e5) + 5);
	int curr = 1;
	for (int i = 1; i < (3e5) + 2; i++) {
		curr = (curr * i) % MOD;
		fact[i] = curr;
	}
	int n;
	cin >> n;
	vector<pair<int, int>>a(n);
	map<int, int>ct;
	map<int, map<int, int>>ct2;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		ct[a[i].first]++;
		ct2[a[i].first][a[i].second]++;
	}
	int bad = 1;
	for (auto it : ct) {
		bad = (bad * fact[it.second]) % MOD;
	}
	int minn = 0,p=1;
	for (auto it : ct2) {
		int curr = 1;
		for (auto jt : it.second) {
			curr =(curr* fact[jt.second])%MOD;
		}
		if (it.second.begin()->first < minn) {
			p = 0;
			break;
		}
		p = (p*curr)%MOD;
		minn = it.second.rbegin()->first;
	}
	ct.clear();
	for (int i = 0; i < n; i++) {
		ct[a[i].second]++;
	}
	int bad2 = 1;
	for (auto it : ct) {
		bad2 = (bad2 * fact[it.second]) % MOD;
	}
	assert((bad + bad2 - p) > 0);
	cout << (MOD+fact[n]-((bad + bad2 - p) % MOD))%MOD << "\n";
	return 0;
}