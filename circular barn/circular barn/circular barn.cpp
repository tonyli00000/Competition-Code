/*
ID: tonyli21
PROG: pails
LANG: C++
*/
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
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	int n;
	long long ans = 1000000000000;
	vector<int>c;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c.push_back(x);
	}
	for (int i = 0; i < c.size(); i++) {
		int sum = 0;
		for (int j = i; j < c.size(); j++) {
			sum += c[j] * (j - i);
		}
		for (int j = 0; j < i; j++) {
			sum += c[j] * (c.size() - i+j);
		}
		if (sum < ans)ans = sum;
	}
	cout << ans << "\n";
	return 0;
}


