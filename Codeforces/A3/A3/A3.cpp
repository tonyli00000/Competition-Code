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
#define INF 10000000
#define MOD 1000000007
#define MAXN 50005
using namespace std;
int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };
long long n, m, c;


int hf(vector<bool>x) {
	int curr = 1, ret = 0;
	for (int i = x.size() - 1; i >= 0; i--) {
		ret += (x[i] * curr);
		curr *= 2;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long i, j, k;
	cin >> n >> m >> c;
	vector<vector<bool>>grid(MAXN, vector<bool>(m));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '.')grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
	vector<int>state(n);
	for (int i = 0; i < n; i++) {
		state[i] = hf(grid[i]);
	}
	for (i = 0; i < c; i++) {
		char c;
		cin >> c;
		long long x1, x2, y1, y2;
		cin >> x1 >> y1;
		x1--; y1--;
		if (c == 'T') {
			grid[x1][y1] = !grid[x1][y1];
			state[x1] = hf(grid[x1]);
			continue;
		}
		cin >> x2 >> y2;
		x2--; y2--;
		
	}
	return 0;
}