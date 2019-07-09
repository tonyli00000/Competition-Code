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

vector<long> st;
vector<long> A;
long start[200002], e[200002];

long left(long p) {
	return p << 1;
}

long r(long p) {
	return (p << 1) + 1;
}
long max(long x, long y, long z) {
	if (z >= x && z >= y)return z;
	if (y >= x &&y >= z)return y;
	if (x >= y && x >= z)return x;
}
void build(long p, long L, long R) {
	if (L == R) {
		st[p] = 1;
	}
	else {
		build(left(p), L, (L + R) / 2);
		build(r(p),(L + R) / 2+1,R);
		long p1 = st[left(p)], p2 = st[r(p)];
		long i,max=0,pr=A[L],ct=1;
		for (i = L + 1; i <= R; i++) {
			if (A[i] == pr)ct++;
			else {
				if (ct > max)max = ct;
				ct = 1;
			}
			pr = A[i];
		}
		if (ct > max)max = ct;
		st[p] = max;
	}
}

long rmq(long p, long L, long R, long i, long j) {
	if (i > R || j < L)return -1;
	if (L >= i && R <= j)return st[p];

	long p1 = rmq(left(p), L, (L + R) / 2, i, j);
	long p2 = rmq(r(p), (L + R) / 2 + 1, R, i, j);
	if (p1 == -1)return p2;
	if (p2 == -1)return p1;
	return (st[p1] >= st[p2]) ? st[p1] : st[p2];
}

int main()
{
	long m, n,i,j,k;
	while (cin >> m) {
		if (m == 0)break;
		cin >> n;
		st.clear();
		st.resize(m*4, 0);
		A.clear();
		A.resize(m, 0);
		for (i = 0; i < 200002; i++) {
			start[i] = -1;
			e[i] = -1;
		}
		long x;
		cin >> x;
		A[0] = x;
		start[x+100000] = 0;
		for (i = 1; i < m; i++) {
			long x;
			cin >> x;
			A[i]=x;
			if (start[x+100000] == -1)start[x+100000] = i;
			if (A[i] != A[i - 1])e[A[i - 1]+100000] = i - 1;
		}
		e[A[m - 1]] = m - 1;
		build(1, 0, m - 1);
		
		for (i = 0; i < n; i++) {
			long x,y;
			cin >> x>>y;
			if (A[x - 1] == A[y - 1])cout << y - x + 1 << "\n";
			else {
				long a1 = e[A[x - 1] + 100000] - (x - 1) + 1;
				long a2 = y - start[A[y - 1] + 100000];
				long a3 = rmq(1, 0, m - 1, e[A[x - 1] + 100000] + 1, start[A[y - 1] + 100000] - 1);
				cout << max(a1, a2, a3) << "\n";
			}
			
		}
	}
	return 0;
}
