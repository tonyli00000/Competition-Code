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

class SA {
private:

	long long lg;
	const bool comp(int x, int y) {
		if (pos[x] != pos[y])return pos[x] < pos[y];
		x += lg, y += lg;
		if (x >= n || y >= n)return y < x;
		return pos[x] < pos[y];
	}
	void build() {
		sa.resize(n);
		vector<int>t(n,0);
		for (int i = 0; i < n; i++) {
			sa[i] = i;
			pos[i] = s[i];
		}
		for (lg = 1;t[n-1]!=n-1; lg << 1) {
			sort(sa.begin(), sa.end(), comp);
			for (int i = 1; i < n; i++) {
				t[i] = t[i - 1];
				if (comp(sa[i - 1], sa[i]))t[i]++;
			}
			for (int i = 0; i < n; i++)pos[sa[i]] = t[i];
		}
	}
	void LCP() {
		lcp.resize(n + 5);
		int ct = 0;
		for (int i = 0; i < n; i++) {
			if (pos[i] == n - 1)continue;
			for (int j = sa[pos[i] + 1]; s[i + ct] == s[j + ct];)
				ct++;
			lcp[pos[i]] = ct;
			if (ct != 0)ct--;
		}
	}
public:
	string s;
	vector<int>sa, pos, lcp;
	int n;
	SA(string x) {
		s = x;
		n = s.length();
		build();
		LCP();
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}