/*
ID: tonyli21
PROG: combo
LANG: C++11
*/
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
#include <algorithm>

using namespace std;
#define OFFSET 1000
#define MAXSOL 1000

int n, ct, i, j,k, aa, bb, cc;
int comb[2][3];
long long solution[MAXSOL], p;

void addsolution(long long p)
{
	int i;
	for (i = 0; i < ct; i++) {
		if (solution[i] == p) return;
	}
	solution[ct] = p;
	ct++;
}

int main() {

	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	cin >> n;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	ct = 0;
	for (i = 0; i < 2; i++) {
		for (int j = a - 2; j <= a + 2; j++)
			for (k = b - 2; k <= b + 2; k++)
				for (int l=c - 2; l <= c + 2; l++) {
					aa = (j + n) % n;
					bb = (k + n) % n;
					cc = (l + n) % n;
					p = aa * OFFSET * OFFSET + bb * OFFSET + cc;
					addsolution(p);
				}
	}
	cout << ct << "\n";

	return 0;
}
