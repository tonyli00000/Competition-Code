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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>x(n);
		int a = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			a ^= x[i];
		}
		if (a == 0 || n % 2 == 0)cout << "First\n";
		else cout << "Second\n";
	}
	return 0;
}