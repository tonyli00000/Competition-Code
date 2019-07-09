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
	int n,i,j,k;
	cin >> n;
	vector<pair<int, int>> intervals;
	for (i = 0; i < n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		x *= -r;
		intervals.push_back(make_pair(x - r, y));
		intervals.push_back(make_pair(x, -y));
	}
	sort(intervals.begin(), intervals.end());
	set<int>happened,current;
	for (int i = 0; i < intervals.size(); ) {
		int j;
		for (j = i; (j < intervals.size()) && (intervals[i].first == intervals[j].first); j++) {
			int y = intervals[j].second;
			if(y<=0)current.erase(-y);
			else current.insert(y);
		}
		if (!current.empty()) {
			happened.insert(*current.begin());
		}
		i = j;
	}
	cout << happened.size() << "\n";
    return 0;
}

