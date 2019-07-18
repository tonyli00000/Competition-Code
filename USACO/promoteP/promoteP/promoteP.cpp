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
#define INF 10000000
#define MOD 1000000007
#define MAXN 100005
using namespace std;
#pragma warning(disable:4996)


struct node{
	int w, id;
};
int n, v[MAXN], BIT[MAXN], ans[MAXN];
int p[MAXN], to[MAXN], child[MAXN], ct = 0;
void add(int x, int y){
	to[++ct] = y;
	child[ct] = p[x];
	p[x] = ct;
}
bool comp(node a, node b){
	return a.w < b.w;
}
void update(int x, int a){
	int i;
	for (i = x; i <= n; i += i & -i) BIT[i] += a;
}
int query(int x){
	int i, ans = 0;
	for (i = x; i; i -= i & -i) ans += BIT[i];
	return ans;
}
void dfs(int x){
	int i;
	ans[x] -= query(v[x]);
	for (i = p[x]; i; i = child[i]) {
		dfs(to[i]);
	}
	ans[x] += query(v[x]);
	update(v[x], 1);
}
int main()
{
	bool debug = 1;
	if (!debug) {
		freopen("promote.in", "r", stdin);
		freopen("promote.out", "w", stdout);
	}
	int i, x;
	cin >> n;
	vector<node>num(n+1);
	for (i = 1; i <= n; i++){
		cin >> num[i].w;
		num[i].id = i;
	}
	sort(num.begin(),num.end(), comp);
	for (i = 1; i <= n; i++)
		v[num[i].id] = n - i + 1;
	for (i = 2; i <= n; i++) {
		cin >> x;
		add(x, i);
	}
	dfs(1);
	for (i = 1; i <= n; i++) cout << ans[i] << "\n";
	return 0;
}