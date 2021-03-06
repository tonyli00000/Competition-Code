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
#pragma warning(disable:4996)

#define INF 10000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int t;
	cin >> t;
	map<string, vector<long long>>a;
	map<string, int>curr;
	while (t--) {
		string op,breed;
		long long n;
		cin >> op;
		if (op == "BUY") {
			cin >> n >> breed;
			if (curr[breed] == a[breed].size())a[breed].push_back(n);
			else a[breed][curr[breed]] = n;
			curr[breed]++;
		}
		if (op == "SELL") {
			cin >> breed;
			curr[breed]--;
		}
		if (op == "QUERY") {
			cin >> n >> breed;
			cout << a[breed][n - 1] << "\n";
		}
	}

	return 0;
}