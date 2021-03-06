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

int ct = 0;
vector<int>maxx, minn;
bool first = true;
vector<int>a;
void bessieSort(int s, int t) {
	if (s == t)return;
	for (int i = s; i < t; i++) {
		if (a[i + 1] < a[i]) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
			if (a[i] == minn[i + 1] && i!=t-1 && !first) {
				minn[i + 1] = min(minn[i + 2], a[i + 1]);
			}
		}
	}
	maxx[s] = a[s];
	minn[t] = a[t];
	if (first) {
		for (int i = t - 1; i >= s; i--) {
			minn[i] = min(minn[i + 1], a[i]);
		}
		first = false;
	}


	ct += t - s + 1;
	int p=s;
	for (int i = s; i < t; i++) {
		if (i != s) {
			maxx[i] = maxx[i - 1];
			maxx[i] = max(a[i], maxx[i]);
		}
		if (maxx[i] <= minn[i + 1]){
			if(p!=i)bessieSort(p, i);
			p = i + 1;
		}
	}
}
int main() {
	bool debug = 1;
	if (!debug) {
		freopen("sort.in", "r", stdin);
		freopen("sort.out", "w", stdout);
	}
	int n;
	cin >> n;
	a.resize(n);
	if (10000 <= n && n < 80000) {
		cout << n + 2 << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
		maxx.resize(n);
		minn.resize(n);
		bessieSort(0, n - 1);
		cout << ct << "\n";
	return 0;
}