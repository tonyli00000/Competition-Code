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

#define INF 1000000000
#define MOD 1000000007
using namespace std;

#define ALL(a) a.begin(),a.end()
vector<pair<string, string>>constraints;
string cow[8] = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue" };
void solve(int curr, vector<bool>used,vector<string>ret) {
	bool bad = false;
	map<string, int>pos;
	for (int i = 0; i < ret.size(); i++)pos[ret[i]] = i;
	for (auto it : constraints) {
		if (!pos.count(it.first) || !pos.count(it.second))continue;
		if (abs(pos[it.first] - pos[it.second]) > 1) {
			bad = true;
			break;
		}
	}
	if (bad)return;
	if (curr == 8) {
		for (auto it : ret)cout << it << "\n";
		exit(0);
	}
	for (int i = 0; i < 8; i++) {
		if (used[i])continue;
		used[i] = true;
		ret.push_back(cow[i]);
		solve(curr + 1, used, ret);
		used[i] = false;
		ret.pop_back();
	}
}
int main()
{
#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool debug = 1;
	if (!debug) {
		freopen("lineup.in", "r", stdin);
		freopen("lineup.out", "w", stdout);
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x, y;
		cin >> x;
		for (int j = 0; j < 4; j++)cin >> y;
		cin >> y;
		constraints.push_back({ x,y });
	}
	sort(cow, cow + 8);
	vector<bool>used(8, false);
	vector<string>ret;
	solve(0, used, ret);
	return 0;
}