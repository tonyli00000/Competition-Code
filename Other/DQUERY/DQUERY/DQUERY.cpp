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
class MergeST {
public:
	vector<vector<int>>tree;
	vector<int>a;
	int n;
	void build(int curr, int l, int r) {
		if (l == r) {
			tree[curr].push_back(a[l]);
			return;
		}
		int mid = l + r >> 1;
		build(2 * curr, l, mid);
		build(2 * curr + 1, mid + 1, r);
		merge(tree[2 * curr].begin(), tree[2 * curr].end(), tree[2 * curr + 1].begin(), tree[2 * curr + 1].end(), back_inserter(tree[curr]));
	}

	int queryHelper(int curr, int l, int r, int LL, int RR, int k) {
		if (RR < l || LL > r)return 0;
		if (LL <= l && RR >= r) {
			int lo = 0, hi = tree[curr].size() - 1;
			if (tree[curr][hi] <= k)return 0;
			if (lo == hi) {
				if (tree[curr][0] > k)return 1;
				return 0;
			}
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (tree[curr][mid] <= k)lo = mid + 1;
				else hi = mid;
			}
			return tree[curr].size() - hi;
		}
		int mid = l + r >> 1;
		return queryHelper(2 * curr, l, mid, LL, RR, k) + queryHelper(2 * curr + 1, mid + 1, r, LL, RR, k);
	}
	int query(int l, int r, int k) { //Number of elements in range of l..r less than k
		return queryHelper(1, 0, n - 1, l, r, k);
	}
	MergeST(vector<int>&x) :a(x) {
		n = x.size();
		tree.resize(4 * n);
		build(1, 0, n - 1);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int>x;
	vector<int>a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (x.find(a[i]) == x.end())b[i] = -1;
		else b[i] = x[a[i]];
		x[a[i]] = i;
	}
	MergeST* T = new MergeST(b);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << (r - l + 1) - T->query(l,r,l - 1) << "\n";
	}
	return 0;
}