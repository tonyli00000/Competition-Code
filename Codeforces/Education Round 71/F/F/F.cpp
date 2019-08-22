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

#define ALL(a) a.begin(),a.end()
using namespace std;

const int MAXN = (5e5) + 5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int t;
	cin >> t;
	vector<int>a(MAXN, 0);
	vector<vector<int>>sum(850, vector<int>(850, 0));
	while (t--) {
		int op,x,y;
		cin >> op>>x>>y;
		if (op == 1) {
			a[x] += y;
			for (int i = 1; i < sum.size(); i++) {
				sum[i][x % i] += y;
			}
		}
		else {
			if (x < sum.size())cout << sum[x][y] << "\n";
			else {
				int ret = 0;
				for (int i = y; i < MAXN; i+=x) {
					ret += a[i];
				}
				cout << ret << "\n";
			}
		}
	}
	return 0;
}