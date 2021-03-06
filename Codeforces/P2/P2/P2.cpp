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
#pragma warning(disable:4996)
#define INF 10000000
#define MOD 1000000007
using namespace std;

struct node {
	int l;
	int r;
	int val;
};
vector<node>T;
vector<int>pre, post;
vector<int>p,sz;
void preorder(int i) {
	if (i == -1)return;
	pre.push_back(T[i].val);
	preorder(T[i].l);
	preorder(T[i].r);
}
void postorder(int i) {
	if (i == -1)return;
	postorder(T[i].l);
	postorder(T[i].r);
	post.push_back(T[i].val);
}
int getroot(int x) {
	if (p[x] == x)return x;
	return getroot(p[x]);
}
void join(int x, int y) {
	int a = getroot(x), b = getroot(y);
	if (a==b)return;
	if (sz[a] < sz[b])swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}
int main()
{
	bool debug = 0;
	if (!debug) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tt = 1; tt<= t; tt++) {
		pre.clear(); post.clear();
		int n, k;
		cin >> n >> k;
		T.resize(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y; x--; y--;
			T[i] = { x,y,i };
		}
		preorder(0);
		postorder(0);
		p.resize(n); sz.assign(n, 1);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		int curr=1;
		vector<int>val(n, -1);
		bool found = true;
		int ct = 0;
		for (int i = 0; i < pre.size(); i++) {
			if (pre[i] != post[i])join(pre[i], post[i]);
			else ct++, p[pre[i]] = -1;
		}

		map<int, int>x;
		for (int i = 0; i < val.size(); i++) {
			if (p[i] == -1)continue;
			int a = getroot(i);
			if (x.find(a) == x.end())x[a] = curr++;
			val[i] = x[a];
		}
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < val.size(); i++) {
			if (val[i] == -1) {
				if (curr <= k)val[i] = curr++;
				else val[i] = 1;
			}
		}
		if (!found || curr!=k+1)cout << "Impossible\n";
		else {
			for (int i = 0; i < val.size(); i++) {
				cout << val[i];
				if (i != val.size() - 1)cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}