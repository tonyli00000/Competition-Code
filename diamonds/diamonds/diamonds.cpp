#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;



int main()
{
	int n;
	int k;
	cin >> n >> k;
	int i;
	map<int, pair<int,int>>v;
	vector<int>x(n);
	for (i = 0; i < n; i++){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int lo = 0, hi = 0;
	vector<int>ret(n);
	while (hi < n) {
		if (x[hi] - x[lo] <= k) {
			ret[lo] = max(ret[lo], hi - lo + 1);
			hi++;
		}
		else lo++;
	}

	for (int i = lo + 1; i<n; i++)
		ret[i] = n - i;
	vector<int>y(n);
	y[n - 1] = ret[n - 1];
	for (int i = n - 2; i >= 0; i--)
		y[i] = max(y[i + 1], ret[i]);

	int ans = 0;
	for (int i = 0; i<n; i++) {
		int tmp = ret[i];
		if (i + ret[i] < n) tmp += y[i + ret[i]];
		ans = max(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}