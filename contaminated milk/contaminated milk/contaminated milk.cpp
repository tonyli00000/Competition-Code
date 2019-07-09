/*
ID: tonyli21
PROG: angry
LANG: C++11
*/
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


int main()
{
	//freopen("paint.in", "r", stdin);
	//freopen("paint.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int>x, y, z;
	vector<int>sick, time;
	map<int, int>drank;
	for (int i = 0; i < c; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		x.push_back(q);
		y.push_back(w);
		z.push_back(e);
		drank[w]++;
	}
	for (int i = 0; i < d; i++) {
		int t, y;
		cin >> t >> y;
		sick.push_back(t);
		time.push_back(y);
	}
	map<int,int>possible;
	for (int i = 0; i < sick.size(); i++) {
		for (int j = 0; j < z.size(); j++) {
			if (z[j] < time[i] && x[j] == sick[i])possible[y[j]]++;
		}
	}
	int ans = 0;
	for (auto it = possible.begin(); it != possible.end(); it++) {
		if (it->second == d) {
			ans = max(ans, drank[d]);
		}
	}
	cout << ans << "\n";
	return 0;
}
