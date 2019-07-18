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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;
#define MAXN 200010
#define MAXD 19

int nex[MAXN][MAXD] = { 0 };
int in[MAXN] = { 0 }, out[MAXN] = { 0 };
int t[MAXN] = { 0 }, ret[MAXN] = { 0 }, n;
long long dist[MAXN] = { 0 }, m;

int main() {
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	cin >> m >> n;
	for (int k = 2; k <= m; k++) {
		int p;
		long long l;
		cin >> p >> l;
		dist[k] = dist[p] + l;
		nex[k][0] = p;
		for (int i = 0; nex[k][i];i++) {
			nex[k][i + 1] = nex[nex[k][i]][i];
		}
	}
	for (int i = 1; i <= m; i++) {
		int c = i;
		for (int j = MAXD - 1; j>=0; j--) {
			if (nex[c][j] && dist[i] - dist[nex[c][j]] <= n) {
				c = nex[c][j];
			}
		}
		in[i]++;
		out[c]++;
		t[i] = c;
	}
	for (int i = m; i >= 1; i--) {
		ret[i] += in[i];
		if (t[i] <i) {
			ret[nex[i][0]] += (ret[i] - out[i]);
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ret[i] << "\n";
	}
	return 0;
}