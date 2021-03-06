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

using namespace std;
#pragma warning(disable:4996)
class hashfunction {
#define mod 982450291
#define X 137
public:
	long long h(string s) {
		long long ret = 0, p = 1;
		for (int i = 0; i < s.length(); i++) {
			ret += ((s[i] * p) % mod);
			p *= X;
			ret %= mod; p %= mod;
		}
		return ret;
	}
};
int main()
{
	bool debug = 0;
	if (!debug) {
		freopen("cownomics.in", "r", stdin);
		freopen("cownomics.out", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string>spot(n), plain(n);
	for (int i = 0; i < n; i++) cin >> spot[i];
	for (int i = 0; i < n; i++) cin >> plain[i];

	int l = 1, r = m;
	hashfunction* H = new hashfunction();
	int minn = m;
	while (l <= r) {
		int mid = (l + r) / 2;
		bool solved = false;
		for (int j = 0; j <= m - mid; j++) {
			set<string>s;
			for (int i = 0; i < n; i++) {
				s.insert(spot[i].substr(j, mid));
			}
			bool found = false;
			for (int i = 0; i < n; i++) {
				if (s.find(plain[i].substr(j, mid)) != s.end()) {
					found = true;
					break;
				}
			}
			if (!found) {
				solved = true;
				break;
			}
		}
		if (!solved)l = mid + 1;
		else r = mid - 1, minn = min(minn, mid);;
	}
	cout << minn << "\n";
	return 0;
}