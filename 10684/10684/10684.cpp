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

using namespace std;

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int n,i;
	while (cin >> n && n != 0) {
		vector<int> m;
		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			m.push_back(x);
		}
		int sum = 0, ans = 0;
		for (i = 0; i < n; i++) {
			sum += m[i];
			ans = max(ans, sum);
			if (sum < 0) {
				sum = 0;
			}
		}
		if (sum == 0)cout << "Losing streak.\n";
		else cout << "The maximum winning streak is " << ans << ".\n";
	}
	return 0;
}
