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
vector<long long>P, Q;

class hashfunction {
#define mod 982450291
#define X1 137
#define X2 151
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
	/*hashfunction(string s, int k) {
	long long p = 1, q = 1;
	//for (int i = 0; i < s.length(); i++)P.push_back(p), Q.push_back(q), p = (p*X1) % mod, q = (q*X2) % mod;
	long long curr = h(s.substr(0, k)); t[curr].push_back(0);
	p = P[k - 1]; q = Q[k - 1];
	for (int i = 1; i <= s.length() - k; i++) {
	long long a = curr / mod, b = curr % mod;
	a = divide(a - s[i - 1], X1, mod) + s[i + k - 1] * p; a %= mod;
	b = divide(b - s[i - 1], X2, mod) + s[i + k - 1] * q; b %= mod;
	curr = a * mod + b;
	t[curr].push_back(i);
	}
	}*/
	/*vector<long long>getpos(string& b) {//gets occurances of b in a
	long long p = h(b);
	if (t.find(p) == t.end())return {};
	return t[p];
	}*/
};
hashfunction* H = new hashfunction();
int solve(string &s, int k,unordered_map<long long,int>&t) {
	int ret = 0;
	long long curr = H->h(s.substr(0, k)); t[curr]++; ret = max(ret, t[curr]);
	long long p = P[k - 1],q = Q[k - 1];
	for (int i = 1; i <= s.length() - k; i++) {
		long long a = curr / mod, b = curr % mod;
		a = H->divide(a - s[i - 1], X1, mod) + s[i + k - 1] * p; a %= mod;
		b = H->divide(b - s[i - 1], X2, mod) + s[i + k - 1] * q; b %= mod;
		curr = a * mod + b;
		t[curr]++; ret = max(ret, t[curr]);
	}
	return ret;
}
int main()
{
	long long p = 1, q = 1;
	for (int i = 0; i < 1000000; i++)P.push_back(p), Q.push_back(q), p = (p*X1) % mod, q = (q*X2) % mod;
	string line;
	bool first = true;
	while (getline(cin, line)) {
		if (!first)cout << "\n";
		first = false;
		stringstream ss(line);
		string a;
		string word;
		int maxx = 0;
		while (ss >> a) {
			word+=a;
			//maxx = max(maxx, (int)a.length());
		}
		for (int i = 1; i <= word.length(); i++) {
			unordered_map<long long, int>t;
			int out = 0;
			out = max(out, solve(word, i, t));
			if (out <= 1)break;
			cout << out << "\n";
		}
		//cout << "\n";
	}
	return 0;
}

