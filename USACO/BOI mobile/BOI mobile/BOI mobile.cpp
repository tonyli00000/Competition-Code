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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, l;
	cin >> n >> l;
	long long i, j, k;
	vector<pair<long long, long long>>pt(n);
	for (i = 0; i < n; i++) {
		cin >> pt[i].first >> pt[i].second;
	}
	sort(pt.begin(), pt.end());
	queue<pair<long long, long long>>Q;
	Q.push(pt[0]);
	long long curr = 1;

	return 0;
}