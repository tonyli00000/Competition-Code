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
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007
using namespace std;
vector<int>p;
int getroot(int x) {
	if (p[x] == x)return x;
	return p[x] = getroot(p[x]);
}
void join(int x, int y) {
	int a = getroot(x), b = getroot(y);
	if (a == b)return;
	p[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
//#define int long long
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		p.resize(n);
		for (int i = 0; i < n; i++)p[i] = i;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			join(x, y);
		}
		map<int, int>ct;
		int maxx = 0;
		for (int i = 0; i < n; i++) {
			ct[getroot(i)]++;
			maxx = max(maxx, ct[getroot(i)]);
		}
		cout << maxx << "\n";
	}
	return 0;
}