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
class MergeST {
public:
	vector<vector<int>>tree;
	vector<int>a;
	int n;
	void build(int curr, int l, int r){
		if (l == r){
			tree[curr].push_back(a[l]);
			return;
		}
		int mid = l + r >> 1;
		build(2 * curr, l, mid);
		build(2 * curr + 1, mid + 1, r);
		merge(tree[2 * curr].begin(), tree[2 * curr].end(), tree[2 * curr + 1].begin(), tree[2 * curr + 1].end(), back_inserter(tree[curr]));
	}

	int queryHelper(int curr, int l, int r, int LL, int RR, int k){
		if (RR < l || LL > r)return 0;
		if (LL <= l && RR >= r){
			int lo = 0, hi = tree[curr].size() - 1;
			if (tree[curr][hi] <= k)return 0;
			if (lo == hi){
				if (tree[curr][0] > k)return 1;
				return 0;
			}
			while (lo < hi){
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
	MergeST(vector<int>&x):a(x) {
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
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	int q;
	cin >> q;
	MergeST* T = new MergeST(x);
	int a, b, c;
	/*cin >> a >> b >> c;
	a--; b--;
	int ans = T->query(a, b, c);
	cout << ans << "\n";
	q--;*/
	while (q--) {
		cin >> a >> b >> c;
		//a ^= ans; b ^= ans; c ^= ans;
		a--; b--;
		int ans = T->query(a, b, c);
		cout << ans << "\n";
	}
	return 0;
}