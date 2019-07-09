#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

vector<pair<double, pair<int, int>>> node;

vector<int>p;
vector<bool>dead(3005, false);
int getroot(int n) {
	if (p[n] == n)return n;
	else {
		if (dead[p[n]])return n;
		return(getroot(p[n]));
	}
}

void join(int i, int j) {
	int x = getroot(i), y = getroot(j);
	if (x == y)return;
	p[x] = y;
	p[y] = y;
}
int main()
{
	int n, m, i, j, k;
	cin >> n >> m;
	p.resize(n + 5);
	for (i = 0; i < n; i++){
		p[i] = i;
	}

	for (i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		join(x, y);
	}
	int prev = getroot(0);
	for (i = 1; i < n; i++){
		if (prev != getroot(i))break;
	}
	if (i == n)cout << "YES\n";
	else cout << "NO\n";
	for (j = 0; j < n - 1; j++){
		int x;
		cin >> x;
		x--;
		dead[x] = true;
		set<int>v;
		for (i = 0; i < n; i++){
			if (!dead[i])v.insert(getroot(i));
		}
		if (v.size()==1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
