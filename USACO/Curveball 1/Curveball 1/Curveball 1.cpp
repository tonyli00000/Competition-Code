#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;


int rk[1505];
int p[1505];

int getroot(int i) {
	if (p[i] == i) return i;
	return getroot(p[i]);
}

void joinset(int a, int b) {
	if (rk[a] >= rk[b]) rk[b] = rk[a];
	else if (rk[a] < rk[b]) rk[a] = rk[b];
	p[a] = b;
	rk[a]--;
	rk[b]--;
}

int hasEdge(int u, int v) {
	int x = getroot(u);
	int y = getroot(v);
	if (x == y)return true;
	if (rk[x] == 1 || rk[y] == 1) {
		joinset(x, y);
		return true;
	}
	rk[x]--; rk[y]--;
	return false;
}

void initialize(int n) {
	for (int i = 0; i<n; i++) {
		p[i] = i;
		rk[i] = n - 1;
	}
}

int main() {
	int n, u, v;
	cin >> n;
	initialize(n);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int x, y;
		cin >> x >> y;
		cout << hasEdge(x, y) << "\n";
	}
	return 0;
}
