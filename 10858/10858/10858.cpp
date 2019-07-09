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

vector< deque<int> > res;

void solve(int n, int div, deque<int> &q) {
	for (int i = div; i * i <= n; i++) {
		if (n % i == 0) {
			q.push_back(i);
			solve(n / i, i, q);
			q.pop_back();
		}
	}
	q.push_back(n);
	res.push_back(q);
	q.pop_back();
}

int main() {
	int n;
	while (cin >> n && n) {
		res.clear();
		deque<int> q;
		solve(n, 2, q);
		cout << res.size() - 1 << "\n";
		for (int i = 0; i < res.size(); i++) {
			if (res[i].size() < 2)continue;
			for (int j = 0;j<res[i].size(); j++) {
				if (j)cout << " ";
				cout << res[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}