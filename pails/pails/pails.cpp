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
	int a, b, c,ans;
	cin >> a >> b >> c;
	for (int i = 0; i <= c / a; i++) {
		for (int j = 0; j <= c / b; j++) {
			if (i*a + j*b <= c)ans = max(ans, i*a + j*b);
		}
	}
	cout << ans << "\n";
	return 0;
}


