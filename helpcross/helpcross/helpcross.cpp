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

long long i, j, k;
vector<long long>chicken;
vector<pair<long long,long long>>cow;

int main()
{
	long long c, a;
	cin >> c >> a;
	for (i = 0; i < c; i++) {
		long long x;
		cin >> x;
		chicken.push_back(x);
	}
	for (i = 0; i < a; i++) {
		long long x,y;
		cin >> x >> y;
		cow.push_back(make_pair(x,y));
	}
	sort(chicken.begin(), chicken.end());
	sort(cow.begin(), cow.end());
	i = 0;
	j = 0;
	long long ct = 0;
	while (i < chicken.size() && j<cow.size()) {
		if (cow[j].first <= chicken[i] && cow[j].second >= chicken[i]) {
			ct++;
			i++;
			j++;
		}
		else {
			if (chicken[i] < cow[j].first)i++;
			else j++;
		}
	}
	cout << ct << "\n";
    return 0;
}

