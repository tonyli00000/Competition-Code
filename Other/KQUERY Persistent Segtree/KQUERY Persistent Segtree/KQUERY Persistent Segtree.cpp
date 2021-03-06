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
using namespace std;
class PersistentSegTree {
private:
	vector<long long>&T;
	struct node {
		long long sum, lazy;
		node *left, *right;
		node(long long s = 0, long long l = 0, node *LL = NULL, node *RR = NULL) {
			sum = s;
			lazy = l;
			left = LL;
			right = RR;
		}
		node *build(int l, int r, vector<long long>&T) {
			if (l == r) {
				sum = T[l];
				return this;
			}
			int mid = (l + r) / 2;
			left = new node();
			right = new node();
			left = left->build(l, mid, T);
			right = right->build(mid + 1, r, T);
			sum = left->sum + right->sum;
			return this;
		}
		node *update(int l, int r, int LL, int RR, long long val) {
			if (l > RR || r < LL) return this;
			if (l >= LL && r <= RR) return new node(sum, lazy + val, left, right);
			long long mid = (l + r) / 2;
			return new node(sum + val * (min(r, RR) - max(l, LL) + 1), lazy, left->update(l, mid, LL, RR, val), right->update(mid + 1, r, LL, RR, val));
		}
		long long query(int l, int r, int LL, int RR, long long val) {
			if (l > RR || r < LL) return 0;
			val += lazy;
			if (l >= LL && r <= RR)	return sum + val * (r - l + 1);
			long long mid = (l + r) / 2;
			return left->query(l, mid, LL, RR, val) + right->query(mid + 1, r, LL, RR, val);
		}
	};
public:
#define MAXN 200000
	vector<node*>root;
	long long curr = 0;//Current root
	int n;
	PersistentSegTree(vector<long long>&x) :T(x) {
		n = x.size();
		root.resize(MAXN);
		root[0] = new node(); //0 is the original root
		root[0] = root[0]->build(0, x.size() - 1, x);
	}
	void update(long long l, long long r, long long val, int t,int last) { //l..r,updated value,new t 
		root[t] = root[last]->update(0, n - 1, l, r, val);
	}
	long long query(long long l, long long r, long long t) { //l..r, root node
		return root[t]->query(0, n - 1, l, r, 0);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<long long, int>>x;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		x.push_back({ a,i });
	}
	map<long long, int>root;
	sort(x.begin(), x.end());
	//root[x.back().first] = 1;
	vector<long long>p(n);
	int ct = 0;
	PersistentSegTree* T = new PersistentSegTree(p);
	int last = 0;
	for (int i = n - 1; i >= 0; i--) {
		int a;
		if (root.find(x[i].first) != root.end())a = root.find(x[i].first)->second;
		else a = ++ct, root[x[i].first] = a;
		T->update(x[i].second, x[i].second, 1, a, last);
		last = a;
	}
	int q;
	cin >> q;
	long long l, r, k,ans;
	cin >> l >> r >> k;
	auto it = root.upper_bound(k);
	if (it == root.end())cout << 0 << "\n",ans=0;
	else ans = T->query(l - 1, r - 1, it->second), cout << ans << "\n";
	while (--q) {
		cin >> l >> r >> k;
		l ^= ans; r ^= ans; k ^= ans;
		auto it = root.upper_bound(k);
		if (it == root.end())cout << 0 << "\n", ans = 0;
		else ans = T->query(l - 1, r - 1, it->second), cout << ans << "\n";
	}
	return 0;
}