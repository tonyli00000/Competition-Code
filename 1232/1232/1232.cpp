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

using namespace std;

vector<long> maxt;
vector<long> mint;

long left(long p) {
	return p << 1;
}
long rt(long p) {
	return (p << 1) + 1;
}

void update(long p, long L, long R, long i, long j, long h) {
	if (i > R || j < L)return;
	update(left(p), L, (L + R) / 2, i, j, h);
	update(rt(p), (L + R) / 2 + 1, R, i, j, h);
	if (maxt[p] < h)maxt[p] = h;
	if (mint[p] == -2 || h < mint[p])mint[p] = h;
}
long long rmq(long long p, long L, long R, long i, long j) {
	if (L > j || i > R)return -1;
	if (L >= i && R <= j)return st[p];

	long long p1 = rmq(left(p), L, (L + R) / 2, i, j);
	long long p2 = rmq(rt(p), (L + R) / 2 + 1, R, i, j);

	if (p1 == -1)return p2;
	if (p2 == -1)return p1;
	return p1 + p2;
}
int main()
{
	int t;
	long i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		maxt.clear();
		maxt.resize(100002, 0);
		mint.clear();
		maxt.resize(100002, -2);
		long n,sum=0;
		cin >> n;
		for (i = 0; i < n; i++) {
			long x, y, z;
			cin >> x >> y >> z;
			long max;
			if (y > max)max = y;
			if (i == 0);
			else {
				sum += rmq(1, 0, max - 1, x - 1, y - 1,z);
			}
			update(1, 0, max - 1, x - 1, y - 1,z);
		}
	}
	return 0;
}
