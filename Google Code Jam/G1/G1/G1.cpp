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

int n;
int sum(vector<double>&x) {
	int ret = 0;
	for (auto i : x) {
		if (i - (int)i >= 0.5)ret += ((int)i + 1);
		else ret += (int)i;
	}
	return ret;
}
bool comp(int a, int b) {
	if ((100 * a) % n > n / 2) return false;
	if ((100 * b) % n > n / 2) return true;
	return (100 * a) % n > (100 * b) % n;
}

int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int l;
		cin >> n >> l;
		vector<int>v(n,0);
		int total = n;
		for (int i = 0; i < l; ++i) {
			cin >> v[i];
			total -= v[i];
		}

		int maxx = (n + 1) / 2;
		sort(v.begin(), v.end(), comp);
		for (int i = 0; total > 0 && i < n; i++) {
			while (total > 0 && (100 * v[i]) % n < (n + 1) / 2) {
				v[i]++;
				total--;
			}
		}
		for (int i = 0; i < n; i++) v[i] *= 100;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += (v[i]) / n;
			if (v[i] % n >= maxx) ans++;
		}
		//multiset<double>all;
		/*int total = 0;
		double add = 1.0 / n * 100.0;
		int ct = 0;
		vector<double>all(l);
		for (int i = 0; i < l; i++) {
			int a;
			cin >> a;
			ct += a;
			all[i] = add * (1.0*a);
			total += all[i];
		}

		for (int i = 0; i < n - ct; i++) {
			all.push_back(0.0);
			double maxx1 = 0, maxx2 = 0;
			int a = -1, b = -1;
			for (int j = 0; j < all.size(); j++) {
				double x = all[j] + add;
				if (x - (int)x >= 0.5) {
					if (maxx2 < x - (int)x) {
						b = j;
						maxx2 = max(maxx2, x - (int)x);
					}
				}
				else {
					if (maxx1 < x - (int)x) {
						a = j;
						maxx1 = max(maxx1, x - (int)x);
					}
				}
			}
			if (maxx2 != 0) all[b] += add;
			else {
				if (maxx1 != 0)all[a] += add;
				else all[0] += add;
			}
			total = sum(all);
		}
		/*for (int i = 0; i < l; i++) {
			int a;
			cin >> a;
			ct += a;
			double y = a / 1.0 / n * 100.0;
			if ((double)y - (int)y >= 0.5) {
				total += ((int)y + 1);
				y = 1.5 - ((double)y - (int)y);
				all.insert(y);
			}
			else {
				total += (int)(y);
				y = 0.5 - ((double)y - (int)y);
				all.insert(y);
			}
		}
		//for (int i = 0; i < n - ct; i++)all.insert(0.5);
		for (int i = 0; i < n - ct; i++) {
			auto it = all.begin();
			
			double y;
			if (*it <= 0.5)y = add + (0.5 - *it);
			else y = add + (1.5 - *it);
			if ((double)y - (int)y >= 0.5) {
				total += ((int)y + 1);
				y = 1.5 - ((double)y - (int)y);
				all.erase(all.begin());
				all.insert(y);
			}
			else {
				total += (int)(y);
				y = 0.5 - ((double)y - (int)y);
				all.erase(all.begin());
				all.insert(y);
			}
			continue;
		}*/
		cout << "Case #" << k << ": " << ans << "\n";
	}
	return 0;
}
