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

#define MAXN 100005
int t[MAXN * 2], x[MAXN * 2], y[MAXN * 2];

vector<int>BIT(MAXN);
long long ans;
struct query{ 
	int x, y, t; 
}Q[MAXN * 2];

bool cmp(query a, query b){ 
	return a.x<b.x;
}

void inc(int x, int z){ 
	for (; x <= MAXN; x += x&-x)BIT[x] += z; 
}

int sum(int x){
	int r = 0; 
	for (; x; x -= x&-x)r += BIT[x]; 
	return r;
}

void solve(int l, int r){
	if (l >= r)return;
	int i, mid = (l + r)/2, ct;
	for (i = l, ct = 0; i <= mid; i++){
		if (t[i]){
			query tmp = { x[i], y[i], t[i] };
			Q[++ct] = tmp;
		}
	}
	for (i = mid; i++ <= r;){
		if (!t[i]){
			query tmp = { x[i], y[i], t[i] };
			Q[++ct] = tmp;
		}
	}
	sort(Q + 1, Q + ct + 1, cmp);
	for (i = 1; i <= ct; i++){
		if (Q[i].t)inc(Q[i].y, 1);
		else ans += sum(MAXN) - sum(Q[i].y);
	}
	for (i = 1; i <= ct; i++){
		if (Q[i].t)inc(Q[i].y, -1);
	}
	solve(l, mid);
	solve(mid + 1, r);
}
int main()
{
	freopen("friendcross.in", "r", stdin);
	freopen("friendcross.out", "w", stdout);
	int n, k, i, ct;
	cin >> n >> k;
	vector<int>a(MAXN), b(MAXN);
	for (i = 1; i <= n; i++){
		long x;
		cin >> x;
		a[x] = i;
	}
	for (i = 1; i <= n; i++){
		long x;
		cin >> x;
		b[x] = i;
	}
	for (ct = 0, i = 1; i + k + 1 <= n; i++){
		x[++ct] = a[i]; 
		y[ct] = b[i]; 
		t[ct] = 1;

		x[++ct] = a[i + k + 1]; 
		y[ct] = b[i + k + 1]; 
		t[ct] = 0;
	}
	solve(1, ct);
	for (ct = 0, i = n; i - k - 1; i--){
		x[++ct] = a[i]; 
		y[ct] = b[i];
		t[ct] = 1;

		x[++ct] = a[i - k - 1]; 
		y[ct] = b[i - k - 1]; 
		t[ct] = 0;
	}
	solve(1, ct);
	cout << ans<<"\n";
	return 0;
}