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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)continue;
			bool check = false;
			if (i != n - 1 && j != m - 1 && a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1])check = true;
			if (i != 0 && j!=m-1&&a[i][j] && a[i - 1][j] && a[i][j + 1] && a[i - 1][j + 1])check = true;
			if (i != 0 && j != 0 && a[i][j] && a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1])check = true;
			if (j != 0 && i!=n-1 && a[i][j] && a[i][j - 1] && a[i + 1][j] && a[i + 1][j - 1])check = true;
			if (!check)cout << -1 << "\n", exit(0);
		}
	}

	vector<pair<int, int>>out;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != n - 1 && j != m - 1 && a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1])out.push_back({ i + 1,j + 1 });
		}
	}
	cout << out.size()<<"\n";
	for (auto it : out) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}