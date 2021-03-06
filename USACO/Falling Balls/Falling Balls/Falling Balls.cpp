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

int dp[505][505];
int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n;
		cin >> n;
		vector<int>ct(n);
		for (int i = 0; i < n; i++) {
			cin >> ct[i];
		}
		int curr = 0;
		if (ct[0] == 0 || ct[n - 1] == 0) {
			cout << "Case #" << k << ": ";
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<string>out(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out[i] += ".";
			}
		}

		bool bad = false;
		int maxx = -1;
		for (int i = 0; i < n; i++) {
			if (ct[i] <= 0)continue;
			if (ct[i] + curr - 1 >= n) {
				bad = true;
				break;
			}
			for (int j = curr; j < curr + ct[i]; j++) {
				if (i == j)continue;
				if (j < i) {
					int p = 0;
					for (int a = j; a < i; a++) {
						out[p][a] = '\\';
						maxx = max(maxx, p);
						p++;
					}
				}
				else {
					int p = 0;
					for (int a = j; a > i; a--) {
						out[p++][a] = '/';
						maxx = max(maxx, p - 1);
					}
				}
			}
			curr += ct[i];
		}
		cout << "Case #" << k << ": ";
		if (bad)cout << "IMPOSSIBLE\n";
		else {
			cout << maxx + 2 << "\n";
			for (int i = 0; i <= maxx + 1; i++) {
				cout << out[i] << "\n";
			}
		}
	}
	return 0;
}
