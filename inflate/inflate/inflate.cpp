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
int i, j, k;

vector<pair<int, int>>problem;
int main()
{
	int m, n;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x>>y;
		problem.push_back(make_pair(x, y));
	}
	long max[10005];
	for (int j = 0; j <= m; j++) {
		max[j] = 0;
		for (int i = 0; i < n; i++) {
			if (problem[i].second <= j) {
				int p = problem[i].first + max[j - problem[i].second];
				if (p > max[j]) max[j] = p;
			}
		}
	}
	cout << max[m] << "\n";
    return 0;
}

