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

struct Tree
{
	vector<long>tree;
	Tree(){
		tree.assign(MAXN * 4, 0);
	}
	void pushup(long rt){
		tree[rt] = max(tree[rt << 1], tree[(rt << 1) + 1]);
	}
	void update(long rt, long l, long r, long p, long d){
		if (l == r){
			tree[rt] = max(tree[rt], d);
			return;
		}
		long mid = (l + r) >> 1;
		if (p <= mid)update(rt << 1, l, mid, p, d);
		else update((rt << 1) + 1, mid + 1, r, p, d);
		pushup(rt);
	}
	int query(long rt, long l, long r, long L, long R){
		if (L <= l && r <= R)return tree[rt];
		int mid = (l + r) >> 1, ret = 0;
		if (L <= mid)ret = max(ret, query(rt << 1, l, mid, L, R));
		if (R > mid)ret = max(ret, query((rt << 1) + 1, mid + 1, r, L, R));
		return ret;
	}
}T;
int main()
{
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	long n;
	cin >> n;
	vector<long>a(n + 1),b(n+1),p(n+1);
	vector<vector<long>>adj(n + 1);
	for (long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (long i = 1; i <= n; i++){
		cin >> b[i];
		p[b[i]] = i;
	}
	for (long i = 1; i <= n; i++){
		long minn = max(long(0), a[i] - 4);
		long maxx = min(n, a[i] + 4);
		adj[i].push_back(0);
		for (long j = minn; j <= maxx; j++){
			adj[i].push_back(p[j]);
		}
		sort(adj[i].begin() + 1, adj[i].end());
	}
	vector<vector<long>>dp(n + 1, vector<long>(15, 0));
	for (long i = 1; i <= n; i++){
		for (long j = 1; j < adj[i].size(); j++){
			if (adj[i][j] - 1 >= 1)dp[i][j] = T.query(1, 1, n, 1, adj[i][j] - 1) + 1;
			else dp[i][j] = 0;
		}
		for (long j = 1; j < adj[i].size(); j++){
			if (adj[i][j] - 1 >= 1)	T.update(1, 1, n, adj[i][j], dp[i][j]);
		}
	}
	cout << T.tree[1] << "\n";
	return 0;
}

