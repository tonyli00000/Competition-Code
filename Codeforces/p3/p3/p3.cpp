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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define INF 3000000LL
#define eps 0.0000004
using namespace std;
inline long long getint() {
	long long _x = 0;
	char _tc = getchar();
	while ((_tc<'0' || _tc>'9') && _tc != '-') _tc = getchar();
	while (_tc >= '0'&&_tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
	return _x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	t = getint();
	for (int k = 1; k <= t; k++) {
		int n, m;
		cin >> n >> m;
		vector<long long>H(n), up(m), down(m), a(m), b(m);
		long long W, X, Y, Z;
		H[0] = getint(), H[1] = getint(), W = getint(), X = getint(), Y = getint(), Z = getint();
		//cin >> H[0] >> H[1] >> W >> X >> Y >> Z;
		for (int i = 2; i < n; i++) {
			H[i] = (W*H[i - 2] + X * H[i - 1] + Y) % Z;
		}
		vector<long long>maxUp(n, INF), maxDown(n, INF);

		for (int i = 0; i < m; i++) {
			a[i] = getint(), b[i] = getint(), up[i] = getint(), down[i] = getint();
			//cin >> a[i] >> b[i] >> up[i] >> down[i];
			a[i]--; b[i]--;
			if (b[i]>a[i]) {
				for (int j = a[i] + 1; j <= b[i]; j++) {
					maxUp[j] = min(up[i], maxUp[j]);
					maxDown[j] = min(down[i], maxDown[j]);
				}
			}
			else {
				for (int j = b[i] + 1; j <= a[i]; j++) {
					maxUp[j] = min(down[i], maxUp[j]);
					maxDown[j] = min(up[i], maxDown[j]);
				}
			}
		}

		long double l = 0.0, r = 1000000.0, ret = r;
		while (l <= r - eps) {
			long double mid = l + 1.0*(r - l) / (long double)2.0;
			bool solved = true;
			pair<long double, long double>curr;
			curr = { max(0.0L, 1.0*H[0] - mid), 1.0*H[0] + mid };
			for (int i = 1; i < n; i++) {
				curr.first -= maxDown[i]; curr.second += maxUp[i];
				curr.first = max(0.0L, curr.first);
				long double maxx = 1.0*H[i] + mid, minn = max(0.0L, 1.0*H[i] - mid);
				if (curr.first>maxx || curr.second < minn) {
					solved = false;
					break;
				}
				curr = { max(0.0L, max(curr.first, minn)), min(curr.second, maxx) };
			}
			if (!solved)l = mid;
			else r = mid, ret = min(ret, mid);
		}
		cout << "Case #" << k << ": ";
		cout << fixed << setprecision(6) << ret << "\n";
	}
	return 0;
}
