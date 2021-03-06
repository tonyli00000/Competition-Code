#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <list>
#include <stack>
#include <ctime>

//#include <bits/stdc++.h>
using namespace std;
ifstream fin("/Users/anneouyang/fhc18/r1-3/fin.txt");
ofstream fout("/Users/anneouyang/fhc18/r1-3/fout.txt");

typedef long long int lli;
const lli LLINF = LONG_LONG_MAX;
const lli MAXN = 200010;
const lli MAXM = 23;
lli n, m, w, x, y, z, a[MAXN];
pair<lli, lli> range[MAXM];
double up[MAXM], down[MAXM];
pair<double, double> req[MAXN];

bool ok(double x) {
	double cup = a[1] + x;
	double cdown = max(a[1] - x, 0.0);
	for (lli i = 2; i <= n; i++) {
		double aa = a[i] + x;
		double bb = max(a[i] - x, 0.0);
		double cc = cup + req[i].first;
		double dd = max((cdown - req[i].second), 0.0);
		cup = min(aa, cc);
		cdown = max(bb, dd);
		if (cup < cdown)
			return 0;
	}
	return 1;
}

double findans() {
	lli lo = 0, hi = LLINF, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (ok(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	if (lo > 0 && ok(lo - 0.5)) {
		return lo - 0.5;
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	fin >> T;
	int curT = 1;
	while (curT <= T) {
		cout << curT << endl;
		fout << "Case #" << curT << ": ";
		fin >> n >> m;
		fin >> a[1] >> a[2] >> w >> x >> y >> z;
		for (int i = 3; i <= n; i++) {
			a[i] = (w * a[i - 2] + x * a[i - 1] + y) % z;
		}
		for (int i = 1; i <= m; i++) {
			fin >> range[i].first >> range[i].second >> up[i] >> down[i];
		}
		for (int i = 0; i <= n; i++) {
			req[i].first = req[i].second = LLINF;
		}
		for (lli i = 1; i <= m; i++) {
			if (range[i].first < range[i].second) {
				for (lli j = range[i].first + 1; j <= range[i].second; j++) {
					req[j].first = min(req[j].first, up[i]);
					req[j].second = min(req[j].second, down[i]);
				}
			}
			else {
				for (lli j = range[i].first; j > range[i].second; j--) {
					req[j].first = min(req[j].first, down[i]);
					req[j].second = min(req[j].second, up[i]);
				}
			}
		}
		curT++;
		fout << fixed << setprecision(6) << findans() << endl;
	}

	return 0;
}
