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

int p[70000], rk[70000];

int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
void changeset(int m, int n) {
	if (p[m] != m)changeset(p[m], n);
	p[m] = n;
}
int convert(string s) {
	int i,m=1,n=0;
	for (i = s.length() - 1; i >= 0; i--) {
		n += m*(s[i] - '0');
		m *= 10;
	}
	return n;
}

void unionset(int x, int y) {
	int a = findset(x), b = findset(y);
	if (rk[a] > rk[b]) {
		p[b] = a;
		changeset(y, a);
	}
	else {
		p[a] = b;
		changeset(x, b);
		if (rk[a] == rk[b])rk[b]++;
	}
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	string line;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		int m;
		cin >> m;
		for (i = 1; i <= m; i++) {
			p[i] = i;
			rk[i] = 0;
		}
		getline(cin, line);
		int f = 0, l = 0;
		while (getline(cin, line) && line!="") {
			stringstream ss(line);
			ss << line;
			string sa, sb,sc;
			ss >> sa >> sb >> sc;
			int x = convert(sb), y = convert(sc);
			if (sa == "q") {
				if (findset(x) != findset(y))f++;
				else l++;
			}
			else {
				if (findset(x) != findset(y))unionset(x, y);
			}
		}
		cout << l << "," << f << "\n";
	}
	return 0;
}
