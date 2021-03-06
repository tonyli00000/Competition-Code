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

struct query {
	int k;
	int l;
	int r;
	int id;
};
bool comp(query x, query y) {
	if (x.k != y.k)return x.k > y.k;
	return x.r > y.r;
}
class segTree {
public:
	vector<int>t;
	int n;
	segTree(int n) {
		t.resize(n * 4 + 5, 0);
		this->n = n;
	}
	void build() {  // build the tree
		for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
	}

	void update(int p, int value) {  // set value at position p
		for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p]+t[p ^ 1];
	}

	int query(int l, int r) {  // sum on interval [l, r)
		int ret = 0;
		r++;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret+= t[l++];
			if (r & 1) ret+=t[--r];
		}
		return ret;
	}

};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>x(n);
	vector<query>query;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		query.push_back({ x[i],i,-1,-1});
	}
	int q, ct = 0;;
	cin >> q;
	vector<int>ans(q);
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		l--; r--;
		query.push_back({ k,l,r ,ct++});
	}
	sort(query.begin(), query.end(), comp);
	segTree* T=new segTree(n);
	for (int i = 0; i < query.size(); i++) {
		if (query[i].r == -1)T->update(query[i].l, 1);
		else {
			ans[query[i].id] = T->query(query[i].l, query[i].r);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}