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

class SparseTable {
public:
	vector<int>num;
	vector<vector<int>>minn;
	vector<vector<int>>g;
	int lg = 24;
	int n;
	int gcd(int a, int b) {
		if (a == 0)return b;
		return gcd(b%a, a);
	}
	void build(){
		int h = log2(n);
		for (int i = 0; i < n; i++) {
			minn[i][0] = g[i][0] = num[i];
		}
		for (int j = 1; j <= h; j++) {
			for (int k = 0; k + (1 << j) - 1 < n; k++) {
				int x = k + (1 << (j - 1));
				minn[k][j] = min(minn[k][j - 1], minn[x][j - 1]);
				g[k][j] = gcd(g[k][j - 1], g[x][j - 1]);
			}
		}
	}
	SparseTable(vector<int>&x):num(x) {
		n = x.size();
		minn.resize(n + 5, vector<int>(lg));
		g.resize(n + 5, vector<int>(lg));
		build();
	}

	int getGCD(int i, int j) {
		int h = log2(j - i + 1);
		return gcd(g[i][h], g[j - (1 << h) + 1][h]);
	}
	int getMin(int i, int j) {
		int h = log2(j - i + 1);
		return min(minn[i][h], minn[j - (1 << h) + 1][h]);
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
	SparseTable* st = new SparseTable(x);
	int l = 1, r = n, maxx = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		bool solved = false;
		for (int i = 0; i<n && i <= n - mid; i++) {
			if (st->getGCD(i, i + mid - 1) == st->getMin(i, i + mid - 1)) {
				solved = true;
			}
		}
		if (solved) l = mid + 1,maxx=max(mid,maxx);
		else r = mid - 1;
	}
	vector<int>out;
	for (int i = 0; i<n && i <= n - maxx; i++) {
		if (st->getGCD(i, i + maxx - 1) == st->getMin(i, i + maxx - 1)) {
			out.push_back(i+1);
		}
	}
	cout << out.size() << " " << maxx - 1 << "\n";
	for (int i = 0; i < out.size(); i++) {
		cout << out[i];
		if (i != out.size())cout << " ";
	}
	cout << "\n";
	return 0;
}