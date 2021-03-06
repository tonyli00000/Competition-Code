#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define INF 10000000
#define MOD 1000000007
using namespace std;

bool comp(pair<long long, long long>x, pair<long long, long long>y) {
	return (x.second - x.first) < (y.second - y.first);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<long long, long long>>can(n);
	for (int i = 0; i < n; i++) {
		cin >> can[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> can[i].second;
	}
	sort(can.begin(), can.end());
	long long sum = 0;
	for (int i = 0; i < n - 2; i++) {
		sum += can[i].first;
	}
	if (can[n - 1].second - can[n - 1].first + can[n - 2].second - can[n - 2].first < sum)cout << "NO\n";
	else cout << "YES\n";
	return 0;
}