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

int s[10002], p[10002], rk[10002];

int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
//void changeset(int m, int n) {
//	if (p[m] != m)changeset(p[m], n);
//	p[m] = n;
//}

void unionset(int x, int y) {
	int a = findset(x), b = findset(y);
	if (rk[a] > rk[b]) {
		p[b] = a;
		s[a] += s[b];
		//changeset(y, a);
	}
	else {
		p[a] = b;
		s[b] += s[a];
		//changeset(x, b);
		if (rk[a] == rk[b])rk[b]++;
	}
}
int main()
{
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, n;
		cin >> m >> n;
		for (i = 0; i < m; i++) {
			p[i] = i;
			rk[i] = 0;
		}
		for (i = 0; i < m; i++) 
			cin >> s[i];
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if (findset(x) != findset(y))unionset(x, y);
		}
		for (i = 0; i < m; i++) {
			if (s[findset(i)] != 0)break;
		}
		if (i == m)cout << "POSSIBLE\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
