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
#include<cassert>
#define INF 10000000
#define MOD 1000000007
using namespace std;
class hashfunction {
#define mod 982450291
#define X1 137
#define X2 31
public:
	unordered_map<long long, vector<long long>>t;
	long long xgcd(long long x, long long y, long long &a, long long &b) {
		if (x == 0) {
			x = 0, y = 1;
			return y;
		}
		long long x1, y1;
		//assert(x > 0);
		long long gcd = xgcd(y%x, x, x1, y1);
		a = y1 - (y / x) * x1;
		b = x1;
		return gcd;
	}
	long long modInverse(long long b, long long m) {
		long long x, y;
		long long g = xgcd(b, m, &x, &y);
		if (g != 1)return -1;
		return (x%m + m) % m;
	}
	long long modDivide(long long a, long long b, long long m) {
		a = a % m;
		long long inv = modInverse(b, m);
		return (inv * a) % m;
	}
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
	long long divide(long long x, long long y) {
		long long a, b;
		long long gcd = xgcd(x, y, a, b);
		return (a%mod + mod) % mod;
	}
	hashfunction(string s, int k) {
		long long curr = h(s.substr(0, k)); t[curr].push_back(0);
		long long p = 1, q = 1;
		for (int i = 1; i < k; i++)p *= X1, p %= mod, q *= X2, q %= mod;
		for (int i = 1; i <= s.length() - k; i++) {
			long long a = curr / mod, b = curr % mod;
			a = modDivide(a - s[i - 1], X1, mod) + s[i + k - 1] * p; a %= mod;
			b = modDivide(b - s[i - 1], X2, mod) + s[i + k - 1] * q; b %= mod;
			curr = a * mod + b;
			t[curr].push_back(i);
		}
	}
	vector<long long>getpos(string b) {//gets occurances of b in a
		long long p = h(b);
		if (t.find(p) == t.end())return {};
		return t[p];
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	bool first = true;
	while (cin>>t) {
		if (!first)cout << "\n";
		first = false;
		string x, y;
		cin >> x >> y;
		if (x.length() > y.length()) {
			cout << "\n";
			continue;
		}
		hashfunction* H = new hashfunction(y, x.length());
		auto it = H->getpos(x);
			for (int i = 0; i < it.size(); i++) {
				cout << it[i] << "\n";
			}
	}
	return 0;
}