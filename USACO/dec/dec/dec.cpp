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

using namespace std;
struct cow {
	int k;
	int p;
	int a;
};
bool comp(cow a, cow b){
	if (a.k != b.k)return a.k<b.k;
	if (a.p != b.p)return a.p<b.p;
	return a.a<b.a;
}
int main() {
	bool debug = 1;
	if (!debug) {
		freopen("dec.in", "r", stdin);
		freopen("dec.out", "w", stdout);
	}
	int n, b;
	cin >> n >> b;
	vector<cow>a(b+1);
	for (int i = 1; i <= b; i++) {
		cin >> a[i].k >> a[i].p >> a[i].a;
	}
	sort(a.begin(), a.end(), comp);
	vector<vector<int>>s(n+5, vector<int>(n+5));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	vector<int>dp((1 << n) + 5, 0);
	for (int i = 0; i <= (1 << n) - 2; i++) {
		int ct = 1,x=0;
		for (int j = 1; j <= n; j++) {
			if (i&(1 << j - 1))ct++;
		}
		for (int j = 1; j <= b; j++) {
			if (a[j].k == ct) { x = j; break; }
		}
		int y = x;
		for (int j = 1; j <= n; j++) {
			if ((i&(1 << j - 1)))continue;
			int tot = 0;
			x = y;
			while (x && x <= b && a[x].k == ct && dp[i] + s[j][ct] + tot >= a[x].p) {
				tot += a[x++].a;
			}
			dp[i | (1 << j - 1)] = max(dp[i | (1 << j - 1)], dp[i] + tot + s[j][ct]);
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
	return 0;
}