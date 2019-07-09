#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;
vector<vector<int>>c;
vector<int>x, y;
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
	{
		// If next element a[i] is greater than last element of
		// current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i])
		{
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

		// Binary search to find the smallest element referenced by b which is just bigger than a[i]
		// Note : Binary search is performed on b (and not a).
		// Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size() - 1; u < v;)
		{
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u = c + 1; else v = c;
		}

		// Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]])
		{
			if (u > 0) p[i] = b[u - 1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main()
{
	int tc,t=0;
	cin >> tc;
	while (tc--) {
		int r,s,w;
		cin >> r >> s >> w;
		x.clear();
		y.clear();
		c.clear();
		c.resize(r*r + 5);
		for (int i = 0; i < c.size(); i++)
			c[i].resize(r*r + 5, 0);
		for (int i = 0; i <= s; i++) {
			int q;
			cin >> q;
			x.push_back(q);
		}
		for (int i = 0; i <= w; i++) {
			int q;
			cin >> q;
			x.push_back(q);
		}
		vector<int>lis;
		find_lis(x, lis);
		cout << "Case " << ++t << ": " << lis.size()<<"\n";
	}
    return 0;
}

