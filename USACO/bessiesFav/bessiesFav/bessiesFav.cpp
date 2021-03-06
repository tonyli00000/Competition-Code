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
#define MAXN 10000
#define MAXP 2000000
using namespace std;

vector<bool>p(MAXP, true);
int main()
{
	std::ios::sync_with_stdio(false);
	long top = 1;
	vector<long long>prime(100005);
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	for (long long i = 3; top <= MAXN; i += 2) {
		if (p[i]) {
			prime[top] = i;
			top++;
			for (long long j = i * 3; j < MAXP; j += i + i) p[j] = false;
		}
	}
	int curr = 0,add=1;
	vector<int>ret(100);
	ret[0] = 2;
	for (int i = 1; i < 100; i++) {
		curr += add;
		curr++;
		add++;
		ret[i] = prime[curr];
	}
	cout << prime[curr] << "\n";
	return 0;
}