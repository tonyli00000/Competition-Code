/*
ID: tonyli21
PROG: skidesign
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
	//freopen("skidesign.in", "r", stdin);
	//freopen("skidesign.out", "w", stdout);
	int n,l=60000,b=-1;
	cin >> n;
	vector<int>h;
	long long best = 100 * 100 * n * 100;
	while (n--){
		int x;
		cin >> x;
		h.push_back(x);
		l = min(l, x);
		b = max(b, x);
	}
	//long long best = 100 * 100 * n * 100;
	sort(h.begin(), h.end());
	if (b - l <= 17)cout << 0 << "\n";
	else{

		for (int i = 0; i < 101; i++) {
			long long cost = 0;
			for (int j = 0; j < h.size(); j++) {
				if (h[j] > i) cost += (h[j] - i) * (h[j] - i);
				if (h[j] < i - 17) cost += (i - 17 - h[j]) * (i - 17 - h[j]);
			}
			best = min(cost, best);
		}
		cout << best << "\n";
	}
	return 0;
}