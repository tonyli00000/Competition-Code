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
	vector<pair<char, int>>all;
	string s;
	cin >> s;
	all.push_back({ s[0],1 });
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == all.back().first)all.back().second++;
		else {
			all.push_back({ s[i],1 });
		}
	}
	int sum = 0;
	for (int i = 0; i < all.size(); i++) {
		if (all[i].first == 'v') {
			all[i].second--;
			sum += all[i].second;
		}
	}
	int curr = 0;
	int ans = 0;
	for (int i = 0; i < all.size(); i++) {
		if (all[i].first == 'v')curr += all[i].second;
		else {
			ans += all[i].second * curr * (sum - curr);
		}
	}
	cout << ans << "\n";
	return 0;
}