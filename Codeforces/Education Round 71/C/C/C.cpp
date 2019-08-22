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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		vector<pair<int, int>>p(1,{ 0,1 });
		for (int i = 1; i < s.length(); i++) {
			int x = s[i] - '0';
			if (p.back().first == x)p.back().second++;
			else p.push_back({ x,1 });
		}
		int ret = 0, ct = 0;
		bool up = false;

		for (int i = 1; i < p.size(); i += 2) {
			if (i == p.size() - 2) {
				if (!up)ret += a, up = true;
				ret += (p[i].second + 1) * b*2;
				ct += p[i].second + 1;
				ret += a;
				break;
			}
			if (!up)ret += a,up=true;
			ret += (p[i].second + 1) * b*2;
			ct += p[i].second + 1;
			if (p[i + 1].second == 1 || (p[i + 1].second - 1) * b < 2*a) {
				ret += (p[i + 1].second - 1) * b*2;
				ct += p[i + 1].second - 1;
			}
			else {
				up = false;
				ret += a;
			}
		}
		ret += a * n;
		ret += (n + 1 - ct) * b;

		cout << ret << "\n";
	}
	return 0;
}