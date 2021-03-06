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
	int n;
	cin >> n;
	set<int>a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.insert(x);
		auto it = a.find(x); it++;
		if (it != a.end())a.erase(it);
	}
	cout << a.size() << "\n";
	return 0;
}