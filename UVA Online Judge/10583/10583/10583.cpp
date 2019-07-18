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

vector<int> p;
vector<int> rk;

int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}

void changeset(int m, int n) {
	if (p[m] == m) {
		p[m] = n;
		rk[p[m]] = rk[n] - 1;
		return;
	}
	else {
		p[m] = n;
		rk[p[m]] = rk[n] - 1;
		changeset(p[m], n);
	}
}

void unionset(int q, int w,int n) {
	int x = findset(q), y = findset(w);
	if (rk[x] > rk[y]) {
		/*for (int i = 1; i <=n ; i++) {
			if (p[i] == w) {
				p[i] = p[q];
				rk[i] -= (rk[q] - rk[w]);
			}
		}*/
		p[y] = p[x];
		changeset(w,x);
	}
	else {
		if (rk[x] == rk[y])rk[y]++;
		//for (int i = 1; i <=n; i++) {
		//	if (p[i] == q) {
		//		p[i] = p[w];
		//		rk[i] -= (rk[w] - rk[q]);
		//	}
		//}
		//
		p[x] = p[y];
		changeset(q, y);
	}
}
int main()
{
	int m, n, i, j, k,t=0;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		t++;
		cout << "Case " << t << ": ";
		rk.clear();
		p.clear();
		rk.resize(m+1, 0);
		for (i = 0; i <= m; i++) {
			p.push_back(i);
		}
		int a, b;
		for (i = 0; i < n; i++) {
			cin >> a >> b;
			int r = findset(a), t = findset(b);
			if (r != t)unionset(a, b,m);
		}
		set<int> v;
		for (i = 1; i <= m; i++) {
			if (v.find(findset(i)) == v.end())v.insert(p[i]);
		}
		cout << v.size() << "\n";
	}
	return 0;
}
