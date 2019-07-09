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
int p[3005];
map<int, bool>open;
int findset(int x) {
	if (p[x] != x)return findset(p[x]);
}
void joinunion(int x, int y) {
	p[x] = y;
}

int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (findset(x) != findset(y))joinunion(x, y);
	}
	for (i = 1; i < n; i++) {
		if (findset(i) != findset(i + 1))break;
	}
	if (i == n)cout << "YES\n";
	else cout << "NO\n";
	for (i = 1; i <= n; i++)
		open[i] = true;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		open[x] = false;
		for (j = 1; j <= n; j++) {
			if(open[j])solve(j)
		}
	}
	
	return 0;
}
