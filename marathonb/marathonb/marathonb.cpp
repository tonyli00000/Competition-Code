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

vector<pair<int, pair<int, int>>>cp;
int main()
{
	long ans = 0;
	int n, m,i,j,k;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (i == 0)cp.push_back(make_pair(0, make_pair(x, y)));
		else {
			int dist = abs(cp[i - 1].second.first - x)+abs(cp[i-1].second.second-y);
			cp.push_back(make_pair(dist, make_pair(x, y)));
		}
	}
	vector<int>solution;
	vector<int>temp;
	for (i = 1; i < n-1; i++) {
		if (cp[i].first + cp[i + 1].first>abs(cp[i + 1].second.first - cp[i].second.first) + abs(cp[i + 1].second.second - cp[i].second.second)) {
			solution.push_back(abs(cp[i + 1].second.second + cp[i].second.second));
			temp.push_back(solution[i - 1]);
		}
		else {
			solution.push_back(-1);
			temp.push_back(solution[i - 1]);
		}
	}
	sort(temp.begin(), temp.end());
	i = solution.size() - 1;
	for (j = 0; j < m; j++) {
		ans -= solution[i - j];
	}
	cout << ans << "\n";
    return 0;
}

