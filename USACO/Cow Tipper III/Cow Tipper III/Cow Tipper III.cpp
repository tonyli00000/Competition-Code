#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 100011
#define MOD 1000000007LL

int N;
pair<int, int> val[MAXN];
set<int> index;

struct segtree {
	int st[4 * MAXN][2], lazy[4 * MAXN];

	void build(int w, int L, int R) {
		if (L == R) {
			st[w][0] = -(int)((L % 2) == 0);
			st[w][1] = -(L % 2);
		}
		else {
			build(w * 2, L, (L + R) / 2);
			build(w * 2 + 1, (L + R) / 2 + 1, R);

			st[w][0] = st[w * 2][0] + st[w * 2 + 1][0];
			st[w][1] = st[w * 2 + 1][1] + st[w * 2][1];
		}
	}

	void push(int w, int L, int R) {
		if (!lazy[w]) return;
		else if (L != R) {
			lazy[w * 2] ^= lazy[w];
			lazy[w * 2 + 1] ^= lazy[w];
		}

		st[w][0] *= -1;
		st[w][1] *= -1;
		lazy[w] = 0;
	}

	void update(int w, int L, int R, int a, int b, int v) {
		push(w, L, R);

		if (b < L || a > R) return;
		else if (a <= L && b >= R) { 
			lazy[w] ^= v;
			push(w, L, R);
		}
		else {

			update(w * 2, L, (L + R) / 2, a, b, v);
			update(w * 2 + 1, (L + R) / 2 + 1, R, a, b, v);

			for (int i = 0; i < 2; i++)
				st[w][i] = st[w * 2][i] + st[w * 2 + 1][i];
		}
	}

	int query(int w, int L, int R, int a, int b, int c) {
		push(w, L, R);

		if (b < L || a > R) return 0;
		else if (a <= L && b >= R) return st[w][c];
		else {

			int q1 = query(w * 2, L, (L + R) / 2, a, b, c);
			int q2 = query(w * 2 + 1, (L + R) / 2 + 1, R, a, b, c);

			return q1 + q2;
		}
	}
};

segtree fwd;
segtree bck;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val[i].first;
		val[i].second = i;
	}

	sort(val + 1, val + N + 1);

	fwd.build(1, 1, N);
	bck.build(1, 1, N);

	//cout << "fuck yeah" << endl;
	
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		int curf = fwd.query(1, 1, N, val[i].second, val[i].second, val[i].second % 2);
		int curb = bck.query(1, 1, N, val[i].second, val[i].second, val[i].second % 2);
	
		long long x = curf*curb*fwd.query(1, 1, N, val[i].second, N, 0)*bck.query(1, 1, N, 1, val[i].second, 1);
		long long y = curf*curb*fwd.query(1, 1, N, val[i].second, N, 1)*bck.query(1, 1, N, 1, val[i].second, 0);

		sum = (sum + (((- x - y)*val[i].first + MOD)% MOD) + MOD) % MOD;
		
		fwd.update(1, 1, N, val[i].second, N, 1);
		bck.update(1, 1, N, 1, val[i].second, 1);

	}

	cout << sum << endl;
	return 0;
}