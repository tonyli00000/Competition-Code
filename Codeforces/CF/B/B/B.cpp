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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		map<long long, long long>ct;
		for (long long i = 0; i < n; i++) {
			long long x;
			cin >> x;
			ct[x]++;
		}
		map<long long, set<long long>>a;
		set<long long>all,xx;
		for (auto it : ct) {
			a[it.second].insert(it.first);
			if (it.second == 2)all.insert(it.first);
			if (it.second >= 3)all.insert(it.first),xx.insert(it.first);
		}
		if (a[1].size() >= k) {
			cout << -1 << "\n";
			continue;
		}
		k -= a[1].size();
		if (all.size() >= k+1) {
			cout << -1 << "\n";
			continue;
		}
		k -= (all.size());
		bool rect;
		if (xx.empty()) {
			rect = all.size() >= 2;
		}
		else {
			rect = (k != 2);
		}
		if (!rect) {
			cout << -1 << "\n";
			continue;
		}
		map<long long, long long>maxx;
		while (k) {
			auto it = all.begin();
			while (k) {
				maxx[*it]++;
				ct[*it]--;
				k--;
				if (ct[*it] == 1) {
					all.erase(it);
					break;
				}
			}
		}
		if (maxx.size()==0||(maxx.size() == 1 && maxx.begin()->second < 3))cout << -1 << "\n";
		else {
			auto it = maxx.rbegin();
			long long x = it->first,y;
			if (it->second >= 3)y = it->first;
			else it++; y = it->first;
			cout << x * y << "\n";
		}
	}
	return 0;
}