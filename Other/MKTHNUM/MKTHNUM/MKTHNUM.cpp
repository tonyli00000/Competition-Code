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
#define INF 100000000
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
	int kthquery(int l, int r, int k,map<int,int>&p) {
		long long lo = -INF, hi = INF;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2;
			int ct = (r-l+1)-query(l, r, mid);
			auto it = p.find(mid);
			if (ct == k && (it != p.end()) && it->second >= l && it->second <= r)
				return mid;
			else if (ct < k)lo = mid + 1;
			else hi = mid - 1;
		}
	}
	MergeST(vector<int>&x) :a(x) {
		n = x.size();
		tree.resize(4 * n);
		build(1, 0, n - 1);
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>x(n);
	map<int, int>p;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		p[x[i]] = i;
	}
	MergeST* T = new MergeST(x);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		i--; j--;
		cout << T->kthquery(i, j, k,p) << "\n";
	}
    return 0;
}

