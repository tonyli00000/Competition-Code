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

long long C(int x, int y) {
	int ct = 2;
	if (y > x / 2)y = x - y;
	long long v = 1;
	for (int i = x; i > x - y; i--) {
		v *= i;
		if (ct <= y && v%ct == 0)v /= ct++;
	}
	return v;
}
int main()
{
	int m, n;
	while (cin >> n) {
		cin >> m;
		long long ans = 1;
		int remain = n;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if(remain!=x && x!=0)ans *= C(remain, x);
			remain -= x;
		}
		cout << ans << "\n";
	}
	return 0;
}
