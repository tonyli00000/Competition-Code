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

#define MOD 1000000007
using namespace std;

struct area {
	int start;
	int height;
};
int main() {
	bool debug = 1;
	if (!debug) {
		freopen("sprinklers.in", "r", stdin);
		freopen("sprinklers.out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<int>maxx(n), minn(n),t(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		t[x] = y;
	}
	vector<area>localMax;
	minn[0] = t[0];
	maxx[n - 1] = t[n - 1];
	localMax.push_back({ n - 1,t[n - 1] });
	for (int i = 1; i < n; i++) 
		 minn[i] = min(minn[i - 1], t[i]);
	for (int i = n - 2; i >= 0; i--) {
		if (t[i] < maxx[i + 1]) maxx[i] = maxx[i + 1];
		else {
			maxx[i] = t[i];
			localMax.push_back({ i, t[i] });
		}
	}
	reverse(localMax.begin(), localMax.end());
	long long ans = 0;
	int curr = 0;
	for (int i = 0; i < n - 1; i++) {
		while (curr < localMax.size() && localMax[curr].start <= i)curr++;
		if (curr == localMax.size())break;
		for (int j = curr; j < localMax.size(); j++) {
			long long h = localMax[j].height - minn[i],range=localMax[j].start-i;
			if (h <= 0)break;
			ans += range*h * (h + 1) / 2;
			if (j == curr)continue;
			long long x = localMax[j - 1].start - i;
			ans -= (h*(h + 1))*x/2;
		}
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}