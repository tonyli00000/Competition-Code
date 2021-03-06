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
using namespace std;
int sq = 805;
bool comp(pair<int,pair<int, int>>x, pair<int,pair<int, int>>y) {
	if (x.second.second / sq == y.second.second / sq)return x.second.first < y.second.first;
	return x.second .second/ sq < y.second.second / sq;
}
vector<long long>P, Q;
class hashfunction {
#define mod 982450291
#define X1 293
#define X2 307
public:
	//vector<long long>P, Q;
	long long mul_inv(long long a, long long b) {
		long long b0 = b, t, q;
		long long x0 = 0, x1 = 1;
		if (b == 1) return 1;
		while (a > 1) {
			q = a / b;
			t = b, b = a % b, a = t;
			t = x0, x0 = x1 - q * x0, x1 = t;
		}
		if (x1 < 0) x1 += b0;
		return x1;
	}

	long long divide(long long a, long long b, long long p) {                // (a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
		long long ans, inv;
		inv = mul_inv(b, p);
		ans = ((a % p) * inv) % p;
		return ans;
	}

	long long h(string s) {
		long long ret = 0, sum = 0;
		for (int i = 0; i < s.length(); i++) {
			ret += ((s[i] * P[i]) % mod);
			ret %= mod;
		}
		for (int i = 0; i < s.length(); i++) {
			sum += ((s[i] * Q[i]) % mod);
			sum %= mod;
		}
		return ret * mod + sum;
	}
	hashfunction() {

	}
};
hashfunction* H = new hashfunction();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long p = 1, q = 1;
	for (int i = 0; i < 1000000; i++)P.push_back(p), Q.push_back(q), p = (p*X1) % mod, q = (q*X2) % mod;
	string s;
	cin >> s;
	int n = s.length();
	vector<long long>sum(n);
	string t = "";
	long long last = 0;
	for (int i = 0; i < n; i++) {
		sum[i] = H->h(s.substr(i, 1));
		long long a = sum[i] / mod, b = sum[i] % mod;
		a *= P[i]; a %= mod;
		b *= Q[i]; b %= mod;
		a = (a + last / mod) % mod, b = (b + last % mod) % mod;
		sum[i] = a * mod + b;
		last = sum[i];
	}

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		long long a = sum[y - 1] / mod, b = sum[y - 1] % mod;
		if (x - 1 >= 0) {
			a += mod, b += mod;
			a -= (sum[x - 1] / mod); a %= mod;
			b -= (sum[x - 1] % mod); b %= mod;
			a = H->divide(a, P[x], mod);
			b = H->divide(b, Q[x], mod);
		}
		else a %= mod, b %= mod;
		cout << a * mod + b << "\n";
	}
	return 0;
}