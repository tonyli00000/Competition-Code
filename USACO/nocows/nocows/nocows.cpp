// nocows.cpp : Defines the entry point for the console application.
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

int i, j, k;
int main()
{
	int x, y;
	cin >> x >> y;
	
	long long dp[105][205];
	for (i = 0; i < 105; i++) {
		for (j = 0; j < 205; j++) {
			dp[i][j] = 0;
		}
	}
	long long s[205];
	for (i = 0; i <= x; i++) s[i] = 0;
	s[1] = 1;

	dp[1][1] = 1;
	for (i = 2; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			dp[i][j] = 0;
			for (k = 1; k < j - 1; k++) {
				int temp = j - 1 - k;
				dp[i][j] += s[k] * dp[i - 1][temp];
				dp[i][j] += s[temp] * dp[i - 1][k];
				dp[i][j]-=dp[i - 1][k] * dp[i - 1][temp];
			}
			dp[i][j] %= 9901;
		}
		for (j = 1; j <= x; j++) {
			s[j] += dp[i][j];
			s[j] %= 9901;
		}
	}
	cout << dp[x][y] << "\n";
    return 0;
}

