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
int t[2005][2005];

int main()
{
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			t[i][j] = -1;
		}
	}
	int x = 1000, y = 1000;
	t[x][y] = 0;
	int ct = 0,ans=1001;
	int n;
	cin >> n;
	while (n--) {
		char c;
		int step;
		cin >> c;
		cin >> step;
		int x2=0, y2=0;
		if (c=='N') x2 = -1;
		if (c == 'S') x2 = 1;
		else if (c == 'W') y2 = -1;
		else {
			y2=1;
		}
		for (int j = 1; j <= step; j++) {
			x += x2;
			y += y2;
			ct++;
			if (t[x][y] >= 0 && ct - t[x][y] < ans) {
				ans = ct - t[x][y];
			}
			t[x][y] = ct;
		}
	}
	if (ans == 1001)cout << "-1\n";
	else {
		cout << ans << "\n";
	}
    return 0;
}

