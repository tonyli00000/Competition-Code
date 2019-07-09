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


int p[30003], rk[30003], s[30003];

int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
void changeset(int m, int n) {
	if (p[m] != m)changeset(p[m], n);
	p[m] = n;
}

void unionset(int x, int y,int a,int b) {
	//int a = findset(x), b = findset(y);
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
	int m, n,i,j,k;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		int t;
		vector<int> a;
		for (i = 0; i < m; i++) {
			p[i] = i;
			rk[i] = 0;
			s[i] = 1;
		}
		for (i = 0; i < n; i++) {
			cin >> t;
			a.resize(t);
			for (j = 0; j < t; j++) {
				int x;
				cin >> x;
				a[j] = x;
			}
			for (j = 0; j < t; j++) {
				for (k = j + 1; k < t; k++) {
					int x = findset(a[j]), y = findset(a[k]);
					if (x!=y)unionset(j, k,x,y);
				}
			}
		}
		int b = findset(0);
		cout << s[b] << "\n";
	}
	return 0;
}
