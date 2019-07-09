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


int main() {
	int t, n, grid[8][8];
	int i, j;

	cin >> t;

	while (t--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		int choice[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int minn = 10000000;
		do {
			int sum = 0;
			for (i = 0; i < n; i++) {
				sum += grid[i][choice[i]];
			}
			minn = min(sum, minn);
		} while (next_permutation(choice, choice + n));

		cout << minn << "\n";
	}

	return 0;
}