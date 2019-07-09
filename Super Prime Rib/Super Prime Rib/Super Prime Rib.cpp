/*
ID: tonyli21
PROG: sprime
LANG: C++11
*/
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

using namespace std;
#define MAXN 10000
long prime[MAXN], top;

int n;

bool isprime(long key)
{
	if (key <= 1) return false;

	int i;
	for (i = 0; (i < top) && (prime[i] < key); i++) {
		if (key % prime[i] == 0) return false;
	}
	return true;
}
void solve(int n, int step,long long out){
	if (step == n){
		cout << out << "\n";
		return;
	}
	for (int i = 1; i < 10; i++){
		if (isprime(out * 10 + i)){
			solve(n,step + 1, out * 10 + i);
		}
	}
}
int main()
{

	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	long i;
	cin >> n;
	prime[0] = 2;
	top = 1;
	for (i = 3; i < MAXN; i += 2) {
		if (isprime(i)) {
			prime[top] = i;
			top++;
		}
	}
	solve(n, 0, 0);
	return 0;
}

