#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX 1000005
#define MOD 1000000007


using namespace std;
long long n,m;
vector<long long>prime(300005, 0);
vector<bool>p(1000005);
vector<pair<long long, int>>f;
long long ans;
int s;
void solve(long step, long long curr) {
	if (step == f.size()) {
		if (curr < n) {
			long long x = (((curr - 1) % MOD)*((n - 1) / curr)) % MOD;
			x = (x* (curr % MOD)) % MOD;
			ans = (ans + x) % MOD;
		}
	}
	else{
		for (long long i = 0; i <= f[step].second; i++) {
			solve(step + 1, curr);
			curr *= f[step].first;
		}
	}
}

int main(){
	bool debug = 0;
	if (!debug){
		freopen("gymnasts.in", "r", stdin);
		freopen("gymnasts.out", "w", stdout);
	}

	cin >> n;
	long long maxx = 1;
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	for (long long i = 3; i < MAX; i += 2) p[i] = true;
	for (long long i = 3; i < MAX; i += 2){
		if (p[i]) {
			prime[maxx++] = i;
			for (long long j = i * 3; j < MAX; j += i * 2) p[j] = false;
		}
	}
	long long x = n;
	for (long long i = 0; i < maxx && prime[i] <= x; i++) {
		if (x % prime[i] == 0) {
			int ct= 0;
			while (x % prime[i] == 0) {
				ct++;
				x /= prime[i];
			}
			f.push_back({ prime[i], ct });
		}
	}
	if (x != 1)f.push_back({ x, 1 });
	s = f.size();
	solve(0, 1);
	cout << (ans + n) % MOD << "\n";
	return 0;
}