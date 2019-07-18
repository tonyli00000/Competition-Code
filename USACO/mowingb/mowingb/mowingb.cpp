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
#define MAX 40000000
#pragma warning(disable:4996)
using namespace std;

long long curnode = 0;
long long val[MAX];
long long lft[MAX];
long long rgt[MAX];
long long maxx = 0;
long long maxy = 0;
long long value;
long long ychild[2][1 << 20] = { 0 };
long long query(long long l, long long r, long long node, long long ql, long long qr){
	if (l > qr || r < ql || node == -1){
		return 0;
	}
	if (l >= ql && r <= qr){
		return val[node];
	}
	long long mid = (l + r) >> 1;
	return query(l, mid, lft[node], ql, qr) + query(mid + 1, r, rgt[node], ql, qr);
}
long long queryx(long long l, long long r, long long tnode, bool k, long long x1, long long y1, long long x2, long long y2){
	if (l > x2 || r < x1 || x1 > x2 || y1 > y2 || ychild[k][tnode] == -1){
		return 0;
	}
	if (l >= x1 && r <= x2){
		return query(1, maxx, ychild[k][tnode], y1, y2);
	}
	long long mid = (l + r) >> 1;
	return queryx(l, mid, tnode + tnode, k, x1, y1, x2, y2) + queryx(mid + 1, r, tnode + tnode + 1, k, x1, y1, x2, y2);
}
void update(long long l, long long r, long long node, long long idx){
	val[node] += value;
	if (l < r){
		long long mid = (l + r) >> 1;
		if (idx <= mid){
			if (lft[node] == -1){
				lft[node] = ++curnode;
				lft[curnode] = -1;
				rgt[curnode] = -1;
				val[curnode] = 0;
			}
			update(l, mid, lft[node], idx);
		}
		else{
			if (rgt[node] == -1){
				rgt[node] = ++curnode;
				lft[curnode] = -1;
				rgt[curnode] = -1;
				val[curnode] = 0;
			}
			update(mid + 1, r, rgt[node], idx);
		}
	}
}
void update(long long l, long long r, long long tnode, bool k, long long idx, long long idy){
	if (ychild[k][tnode] == -1){
		ychild[k][tnode] = ++curnode;
		val[curnode] = 0;
		lft[curnode] = -1;
		rgt[curnode] = -1;
	}
	update(1, maxx, ychild[k][tnode], idy);
	if (l < r){
		long long mid = (l + r) >> 1;
		if (idx <= mid)update(l, mid, tnode + tnode, k, idx, idy);
		else update(mid + 1, r, tnode + tnode + 1, k, idx, idy);
	}
}
long long n, t;
long long x[100005];
long long y[100005];
long long ans = 0;
map <long long, long long> m1, m2;
void insert(long long idx){
	if (x[idx] == x[idx - 1]){//vertical line with same x
		value = 1;
		update(1, maxy, 1, 0, m2[min(y[idx], y[idx - 1]) + 1], m1[x[idx]]);
		value = -1;
		update(1, maxy, 1, 0, m2[max(y[idx], y[idx - 1])], m1[x[idx]]);
	}
	else{
		value = 1;
		update(1, maxy, 1, 1, m2[y[idx]], m1[min(x[idx], x[idx - 1]) + 1]);
		value = -1;
		update(1, maxy, 1, 1, m2[y[idx]], m1[max(x[idx], x[idx - 1])]);
	}
}
long long solve(long long idx){
	if (x[idx] == x[idx - 1]) return queryx(1, maxy, 1, 1, m2[min(y[idx], y[idx - 1]) + 1], m1[1], m2[max(y[idx], y[idx - 1]) - 1], m1[x[idx]]);
	else return queryx(1, maxy, 1, 0, m2[1], m1[min(x[idx], x[idx - 1]) + 1], m2[y[idx]], m1[max(x[idx], x[idx - 1]) - 1]);
}
int main(){
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	m1[1]=0;
	m2[1]=0;
	cin >> n >> t;
	for (long long i = 1; i <= n; ++i){
		cin >> x[i] >> y[i];
		m1[x[i]]=0;
		m1[x[i] + 1]=0;
		m1[x[i] - 1]=0;
		m2[y[i]]=0;
		m2[y[i] + 1]=0;
		m2[y[i] - 1]=0;
	}
	for (auto it = m1.begin(); it != m1.end(); it++){
		m1[it->first] = ++maxx;
	}
	for (auto it = m2.begin(); it != m2.end(); it++){
		m2[it->first] = ++maxy;
	}
	for (long long i = 1; i <= n; ++i){
		if (i - t - 1 > 1)insert(i - t - 1);
		if (i > 1)ans += solve(i);
	}
	cout << ans << "\n";
	return 0;
}