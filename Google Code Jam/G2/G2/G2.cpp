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

struct cmp {
	bool operator()(const int& a, const int& b) const {
		return a < b;
	}
};
int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n;
		cin >> n;
		vector<int>d(n), a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> a[i] >> b[i];
		}
		
		multiset<int>all;
		int lo = 0, hi = n - 1;
		while (lo <= hi) {
			int mid= lo + (hi - lo) / 2;
			bool found = false;
			for (int i = 0; i < n - mid; i++) {
				int j = i + mid;
				map<int, int>ct1, ct2;
				map<pair<int, int>, int>times;
				for (int k = i; k <= j; k++) {
					int x = d[k] + a[k], y = d[k] - b[k];
					ct1[x]++;
					ct2[y]++;
					times[{x, y}]++;
				}
				vector<pair<int, int>>x, y;
				for (auto it : ct1)x.push_back({ it.second,it.first });
				for (auto it : ct2)y.push_back({ it.second,it.first });
				sort(x.begin(), x.end());
				sort(y.begin(), y.end());
				int maxx = 0;
				for (int k = x.size() - 1; k >= 0; k--) {
					if (maxx == j - i + 1)break;
					int best = 0;
					for (int v = y.size() - 1; v >= 0; v--) {
						if (maxx == j - i + 1)break;
						if (x[k].first + y[v].first < best)break;
						best = max(best, x[k].first + y[v].first - times[{x[k].second, y[v].second}]);
						maxx = max(maxx, x[k].first + y[v].first - times[{x[k].second, y[v].second}]);
					}
				}
				if (maxx == j - i + 1) {
					all.insert(maxx);
					found = true;
				}
			}
			if (found) {
				lo = mid;
			}
			else hi = mid;
		}
		if(n==1)cout << "Case #" << k << ": " << 1 << " " <<1 << "\n";
		else cout << "Case #" << k << ": " << *all.rbegin()<<" "<<all.count(*all.rbegin())<<"\n";
	}
	return 0;
}
