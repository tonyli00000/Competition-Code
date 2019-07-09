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

int main()
{
	int m, n;
	while (cin >> m >> n) {
		int ans = 0;
		for (int i = m; i <= n; i++) {
			vector<int>digits;
			int j = i;
			while (j > 0) {
				digits.push_back(j % 10);
				j /= 10;
			}
			bool repeat = false;
			for (j = 0; j < digits.size() && !repeat; j++) {
				for (int k = j + 1; k < digits.size(); k++) {
					if (digits[j] == digits[k])repeat = true;
				}
			}
			if (!repeat)ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
