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
#define MAXN 200005
using namespace std;
vector<int>q(MAXN);
class segTree {
	struct T {
		int l, r;
		long long sum, lazy;
		long long v, len;
		void update(long long x) {
			sum += (r - l + 1)*x;
			lazy += x;
		}
	};
public:
	vector<T>tree;
	segTree(int n) {
		tree.resize(n * 4 + 5);
	}
	void pushDown(int curr) {
		long long lazy = tree[curr].lazy;
		if (lazy) {
			int l = curr << 1, r = curr << 1 | 1;
			tree[l].update(lazy);
			tree[r].update(lazy);
			tree[curr].lazy = 0;
		}
	}

	void pushUp(int curr) {
		int l = curr << 1, r = curr << 1 | 1;
		tree[curr].sum = tree[l].sum + tree[r].sum;
	}

	void build(int l, int r, int curr) {
		tree[curr].l = l, tree[curr].r = r, tree[curr].sum = tree[curr].lazy = 0;
		tree[curr].len = 0;
		if (r == l) return;
		build(l, (r + l) / 2, curr << 1);
		build((r + l) / 2 + 1, r, curr << 1 | 1);
	}

	void update(int LL, int RR, long long x, int curr = 1) {
		int l = tree[curr].l, r = tree[curr].r;
		if (LL == l && RR == r) {
			tree[curr].v += x;
			if (tree[curr].v == 1)tree[curr].len = q[r + 1] - q[l];
			if (tree[curr].v == 0)if (LL == RR)tree[curr].len = 0;
			else tree[curr].len = tree[curr << 1].len + tree[curr << 1 | 1].len; return;
		}
		int mid = tree[curr].l + tree[curr].r>>1;
		if (r <= mid) update(l, r, x,curr<<1); else if (l>mid) update(l, r, x, curr << 1 | 1);
		else update(l, mid, x,curr<<1), update(mid + 1, r, x,curr << 1 | 1);
		if (!tree[curr].v)tree[curr].len = tree[curr << 1].len + tree[curr << 1 | 1].len;
	}

	long long query(int LL, int RR, int curr = 1) {
		int l = tree[curr].l, r = tree[curr].r;
		int m = (l + r) / 2, ls = curr << 1, rs = curr << 1 | 1;
		if (LL <= l && r <= RR)return tree[curr].sum;
		else {
			pushDown(curr);
			long long ret = 0;
			if (LL <= m)ret += query(LL, RR, ls);
			if (RR > m)ret += query(LL, RR, rs);
			return ret;
		}
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>l(MAXN),r(MAXN);
	int x[MAXN],pos=1;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		x[pos++] = l[i];
		x[pos++] = r[i];
	}
	sort(x + 1, x + pos + 1);
	int ct = unique(x + 1, x + pos + 1) - x - 1;
	segTree* T = new segTree(ct);
	T->build(1, ct - 1,1);
	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(x + 1, x + ct + 1, l[i]) - x;
		r[i] = lower_bound(x + 1, x + ct + 1, r[i]) - x - 1;
		T->update(l[i], r[i], 1,1);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		T->update(l[i], r[i], -1,1);
		ans = max(ans, T->tree[1].len);
		T->update(l[i], r[i], 1,1);
	}
	cout << ans << "\n";
	return 0;
}