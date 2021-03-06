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

bool comp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int p[4][2] = { {0,0},{2,5},{5,0},{7,5} };
	string s;
	cin >> s;
	vector<vector<int>>pos(10);
	for (int i = 0; i < s.size(); i++) {
		pos[s[i] - '0'].push_back(i);
	}
	int minn = 10000;
	for (int i = 0; i < 4; i++) {
		int x = pos[p[i][0]].size(), y = pos[p[i][1]].size();
		int a = p[i][0], b = p[i][1];
		if (x == 0 || y == 0)continue;
		if (a==b && x == 1)continue;
		int p1=pos[a][x-1], p2= pos[b][y - 1];
		if (min(p1, p2) == 0 && s[1] == '0' && (i == 1 || i == 3))continue;
		if (a == b) p1 = pos[a][x - 2];
		int ans = abs(p1 - ((int)s.size()-2)) + abs(p2 - ((int)s.size()-1));
		if (p1 > p2) {
			ans= abs(p1 - ((int)s.size() - 1))+ abs((p2) - ((int)s.size() - 2))+1;
		}
		//if (p1 == s.size() - 1)ans--;
		if (p2 == p1 - 1 && p1 == s.size() - 1)ans = 1;
		minn = min(ans, minn);
	}
	if (minn == 10000)cout << "-1\n";
	else cout << minn<<"\n";

	return 0;
}