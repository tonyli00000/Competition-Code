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
#define MAXN 300000
	vector<node*>root;
	long long curr = 0;//Current root
	int n;
	PersistentSegTree(vector<long long>&x):T(x) {
		n = x.size();
		root.resize(MAXN);
		root[0] = new node(); //0 is the original root
		root[0] = root[0]->build(0, x.size() - 1, x);
	}
	void update(long long l, long long r, long long val,long long t) { //l..r,updated value,new t 
		root[t] = root[t - 1]->update(0, n - 1, l, r, val);
	}
	long long query(long long l, long long r, long long t) { //l..r, root node
		return root[t]->query(0, n - 1, l, r, 0);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long>x(n);
	for (long long i = 0; i < n; i++) {
		cin >> x[i];
	}
	PersistentSegTree* T = new PersistentSegTree(x);
	long long curr = 0;
	while (q--) {
		char op;
		cin >> op;
		long long l, r, d;
		if (op == 'C') {
			cin >> l >> r >> d;
			l--; r--;
			T->update(l, r, d, ++curr);
		}
		else if (op == 'Q') {
			cin >> l >> r;
			l--; r--;
			cout << T->query(l, r, curr)<<"\n";
		}
		else if (op == 'H') {
			cin >> l >> r >> d;
			l--; r--;
			cout << T->query(l, r, d) << "\n";
		}
		else cin >> curr;
	}
	return 0;
}