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

#define INF 10000000000
#define MOD 1000000007

#define ALL(a) a.begin(),a.end()
using namespace std;
class Solution {
public:
	vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
		vector<pair<int, pair<string, string>>>all(username.size());
		for (int i = 0; i < username.size(); i++) {
			all[i] = { timestamp[i],{ username[i],website[i] } };
		}
		sort(all.begin(), all.end());
		map<string, vector<string>>p;
		for (int i = 0; i < all.size(); i++) {
			p[all[i].second.first].push_back(all[i].second.second);
		}
		map<pair<string, pair<string, string>>, unordered_set<string>>ct;
		for (auto it : p) {
			if (it.second.size() < 3)continue;
			vector<string>& a = it.second;
			int n = a.size();
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					for (int k = j + 1; k < n; k++) {
						ct[{a[i], { a[j],a[k] }}].insert(it.first);
					}
				}
			}
		}

		int maxx = 0;
		pair < string, pair<string, string>> ret;
		for (auto it : ct) {
			if (it.second.size() > maxx) {
				ret = it.first;
				maxx = it.second.size();
			}
		}
		vector<string>out;
		out.push_back(ret.first);
		out.push_back(ret.second.first);
		out.push_back(ret.second.second);
		return out;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long

	return 0;
}