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
unordered_set<long long>t;
class hashfunction {
#define mod 982450291
#define X1 137
#define X2 151
public:
	//unordered_map<long long, set<long long>>t;
	long long xgcd(long long a, long long b, long long *x, long long *y) {
		if (a == 0) {
			*x = 0, *y = 1;
			return b;
		}
		long long x1, y1;
		long long gcd = xgcd(b%a, a, &x1, &y1);
		*x = y1 - (b / a) * x1;
		*y = x1;
		return gcd;
	}

	long long h(string s) {
		long long ret = 0, p = 1, sum = 0;
		for (int i = 0; i < s.length(); i++) {
			ret += ((s[i] * p) % mod);
			p *= X1;
			ret %= mod; p %= mod;
		}
		p = 1;
		for (int i = 0; i < s.length(); i++) {
			sum += ((s[i] * p) % mod);
			p *= X2;
			sum %= mod; p %= mod;
		}
		return ret * mod + sum;
	}
	long long modInverse(long long b, long long m) {
		long long x, y;
		long long g = xgcd(b, m, &x, &y);
		if (g != 1)return -1;
		return (x%m + m) % m;
	}
	long long divide(long long a, long long b, long long m) {
		a = a % m;
		long long inv = modInverse(b, m);
		return (inv * a) % m;
	}

	hashfunction(string s, int k,unordered_set<long long>&t) {
		long long curr = h(s.substr(0, k)); t.insert(curr);
		long long p = 1, q = 1;
		for (int i = 1; i < k; i++)p *= X1, p %= mod, q *= X2, q %= mod;
		for (int i = 1; i <= s.length() - k; i++) {
			long long a = curr / mod, b = curr % mod;
			a = divide(a - s[i - 1], X1,mod) + s[i + k - 1] * p; a %= mod;
			b = divide(b - s[i - 1], X2,mod) + s[i + k - 1] * q; b %= mod;
			curr = a * mod + b;
			t.insert(curr);
		}
	}

};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	string a, b;
	cin >> a >> b;

	int l = 1, r = max(a.length(), b.length());
	int n = a.length(), m = b.length();
	int maxx = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		t.clear();
		hashfunction* H = new hashfunction(a, mid,t);
		unordered_set<long long>k;
		H = new hashfunction(b, mid, k);
		bool found = false;
		for (auto it : k) {
			if (t.find(it) != t.end()) {
				found = true;
				break;
			}
		}
		if (found)maxx = max(maxx, mid), l = mid + 1;
		else r = mid - 1;
	}
	cout << maxx << "\n";
	return 0;
}