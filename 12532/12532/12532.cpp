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

vector<int> a;
vector<int> st;

long left(long p) {
	return p << 1;
}
long rt(long p) {
	return (p << 1) + 1;
}

void build(long p, long L, long R) {

	if (L == R)st[p] = a[L];
	else {
		build(left(p), L, (L + R) / 2);
		build(rt(p), (L + R) / 2 + 1, R);
		st[p] = st[left(p)] * st[rt(p)];
	}
}

void update(long p, long L, long R, long i, long j) {
	if (i>R || j<L)return;
	if (L == R)st[p] = a[L];
	else {
		update(left(p), L, (L + R) / 2, i, j);
		update(rt(p), (L + R) / 2 + 1, R, i, j);
		st[p] = st[left(p)] *st[rt(p)];
	}
}
long long rmq(long long p, long L, long R, long i, long j) {
	if (L > j || i > R)return 2;
	if (L >= i && R <= j)return st[p];

	long long p1 = rmq(left(p), L, (L + R) / 2, i, j);
	long long p2 = rmq(rt(p), (L + R) / 2 + 1, R, i, j);

	if (p1 == 2)return p2;
	if (p2 == 2)return p1;
	return p1 * p2;
}

int main()
{
	long m, n,i,j,k;
	while (cin >> m >> n) {
		a.clear();
		st.clear();
		st.resize(m * 4, 0);
		for (i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (x > 0)x = 1;
			else {
				if (x < 0)x = -1;
			}
			a.push_back(x);
		}
		build(1, 0, m - 1);
		string line;
		long ct = 0;
		while (ct<n) {
			cin >> line;
			long x, y;
			cin >> x >> y;
			if (line == "P") {
				int q = rmq(1, 0, m - 1, x - 1, y - 1);
				
				if (q > 0)cout << "+";
				else {
					if (q == 0)cout << 0;
					else cout << "-";
				}
			}
			else {
				if (y > 0)a[x-1] = 1;
				else {
					if (y < 0)a[x-1] = -1;
					else a[x - 1] = 0;
				}
				update(1, 0, m - 1, x - 1, x - 1);
			}
			ct++;
		}
		cout << "\n";
	}
	return 0;
}
