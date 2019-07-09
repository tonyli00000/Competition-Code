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
vector<long long>st;

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
		st[p] = st[left(p)] + st[rt(p)];
	}
}

void update(long p, long L, long R, long i, long j) {
	if (i>R||j<L)return;
	if (L == R)st[p] = a[L];
	else {
		update(left(p), L, (L + R) / 2,i,j);
		update(rt(p), (L + R) / 2 + 1, R,i,j);
		st[p] = st[left(p)] + st[rt(p)];
	}
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
	long n, i, j, k,ct=0;
	while (cin >> n && n != 0) {
		if (ct != 0)cout << "\n";
		cout << "Case " << ++ct << ":\n";
		a.clear();
		st.clear();
		st.resize(4 * n, 0);
		for (i = 0; i < n; i++) {
			cin >> k;
			a.push_back(k);
		}
		build(1, 0, n - 1);
		string line;
		getline(cin, line);
		while (cin>>line && line != "END") {
			long x, y;
			cin >> x >> y;
			if (line == "M")cout << rmq(1, 0, n - 1, x-1, y-1)<<"\n";
			else {
				a[x - 1] = y;
				update(1, 0, n - 1, x - 1, x-1);
			}
		}
	}
	return 0;
}
