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
long long P[1000005], Q[1000005];
#define mod 982450291
#define X1 37
#define X2 53

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
long long a,b;
string s;
long long x[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	long long p = 1, q = 1;
	for (int i = 0; i < 1000000; i++)P[i]=p, Q[i]=q, p = (p*X1) % mod, q = (q*X2) % mod;
	
	long long last = 0;
	for (int i = 0; i < n; i++) {
		long long g=h(s.substr(i, 1));
		a = g / mod, b = g % mod;
		a *= P[i]; a += last / mod; a %= mod;
		b *= Q[i]; b += last % mod; b %= mod;
		x[i] = a * mod + b;
		last = x[i];
	}

	vector<int>pos;
	for (int i = 1; i < n; i++) {
		a = x[n - 1] / mod, b = x[n - 1] % mod;
		a += mod, b += mod;
		a -= x[n - 1 - i] / mod, b -= x[n - 1 - i] % mod;
		a %= mod, b %= mod;
		a = divide(a, P[n - i], mod);
		b = divide(b, Q[n - i], mod);
		if (a*mod + b == x[i - 1])pos.push_back(i);
	}
	int l = 0, r = pos.size() - 1;
	int ret = 0;
	while (l <= r) {
		if (ret > pos[r])break;
		int mid = (l + r) / 2;
		bool found = false;
		int k = pos[mid];
		long long curr = h(s.substr(0, k));
		long long f = curr;
		for (int i = 1; i <= s.length() - k - 1; i++) {
			long long a = curr / mod, b = curr % mod;
			a = divide(a - s[i - 1], X1, mod) + s[i + k - 1] * P[k-1]; a %= mod;
			b = divide(b - s[i - 1], X2, mod) + s[i + k - 1] * Q[k-1]; b %= mod;
			curr = a * mod + b;
			if (curr == f) {
				found = true;
				break;
			}
		}
		if (found)l = mid + 1, ret = max(ret, pos[mid]);
		else r = mid - 1;
	}
	if (ret == 0)cout << "Just a legend\n";
	else cout << s.substr(0, ret) << "\n";
	return 0;
}