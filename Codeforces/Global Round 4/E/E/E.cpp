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
using namespace std;

string s;
void output(set<long long>& out) {
	for (auto it : out) {
		cout << s[it];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	set<int>a[3], b[3];
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a'].insert(i);
	}
	int need = s.length() / 2;
	bool found = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)b[j] = a[j];
		set<int>out;
		int curr = 2;
		if (b[i].empty())continue;
		int l = *b[i].begin(), r = *b[i].rbegin();
		b[i].erase(b[i].begin());
		if (l == r)curr = 1;
		else b[i].erase(*b[i].rbegin());
		out.insert(l);
		out.insert(r);
		if (curr >= need) {
			found = true;
			output(out);
			exit(0);
		}
		int last = -1;
		while (out.size() < need && last != curr) {
			int select = 0, d = INF;
			int currL, currR;
			for (int j = 0; j < 3; j++) {
				if (b[j].empty())continue;
				if (b[j].upper_bound(l) == b[j].end())continue;
				int ll = *b[j].upper_bound(l);
				if (*b[j].begin() >= r)continue;
				auto it = b[j].lower_bound(r);
				it--;
				int rr = *it;
				if (abs(ll - l) + abs(rr - r) < d) {
					d = abs(ll - l) + abs(rr - r);
					select = j;
					currL = ll, currR = rr;
				}
			}
			if (d == INF)break;
			l = currL;
			r = currR;
			out.insert(l);
			out.insert(r);
			if (l == r)break;
		}
		if (out.size() >= need) {
			output(out);
			exit(0);
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}