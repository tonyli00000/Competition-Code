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
	int k;
	cin >> k;
	vector<int>s(k);
	for (int i = 0; i < k; i++)cin >> s[i];
	vector<int>g(10005,0);
	g[0] = 0;
	for (int i = 1; i < g.size(); i++) {
		unordered_set<int>x;
		for (int j = 0; j < k; j++) {
			if (i - s[j] < 0)continue;
			x.insert(g[i - s[j]]);
		}
		for (int j = 0; j < 105; j++) {
			if (x.find(j) == x.end()) {
				g[i] = j;
				break;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int p,a;
		cin >> p;

		p = g[p];
		for (int i = 1; i < n; i++)cin >> a, p ^= g[a];
		if (p == 0)cout << "L";
		else cout << "W";
	}
	cout << "\n";
	return 0;
}