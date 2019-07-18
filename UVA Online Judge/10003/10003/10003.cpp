#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int l, n;
int c[50 + 3];
int dp[50 + 3][50 + 3];

int bktk(int x, int y)
{
	if (x + 1 == y) return 0;

	if (dp[x][y] != -1)return dp[x][y];
	int cost = 0;
	int minimum = INT_MAX;
	for (int i = x + 1; i < y; i++) {
		cost = bktk(x, i) + bktk(i, y) + c[y] - c[x];
		if (cost < minimum) minimum = cost;
	}

	return dp[x][y] = minimum;
}

void reset()
{
	for (int i = 0; i < 53; i++) {
		for (int j = 0; j < 53; j++)
			dp[i][j] = -1;
	}
}

int main()
{
	while (cin>>l && l) {
		cin >> n;

		for (int i = 1; i <= n; i++)cin >> c[i];

		c[0] = 0;
		c[n + 1] = l;

		reset();

		cout<<"The minimum cutting is "<< bktk(0, n + 1)<<".\n";
	}

	return 0;
}