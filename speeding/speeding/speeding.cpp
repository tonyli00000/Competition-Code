/*
ID: tonyli21
PROG: angry
LANG: C++11
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
	/*freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);*/
	int x, y, sum = 1, limit[105];
	cin >> x >> y;
	while (x--) {
		int a, b;
		cin >> a >> b;
		for (int i = sum; i <= sum+a; i++)limit[i] = b;
		sum += a;
	}
	sum = 1;
	int ans = 0;
	while (y--) {
		int a, b;
		cin >> a >> b;
		for (int i = sum; i < sum + a; i++) {
			if(limit[i]<b)ans = max(ans, b-limit[i]);
		}
		sum += a;
	}
	cout << ans << "\n";
	return 0;
}
