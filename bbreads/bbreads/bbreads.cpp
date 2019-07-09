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
#include <stdio.h>
#include <stdlib.h>
#define MOD 2012
#pragma warning(disable:4996)

using namespace std;

vector<vector<int>>dp; //# of ways to assign parentheses at location i with j unmatched '('
int i, j, k;
int n;
string line;
vector<int>unmatched;//counts the unmatched '(' at location i

long solve(int index, int x){ 
	if (index == n)return 1;
	if (dp[index][x] != -1)return dp[index][x];
	if (line[index] == '('){
		dp[index][x] = (solve(index + 1, x + 1) + solve(index + 1, x))%MOD;
		return dp[index][x];
	}
	else{
		long long a=0, b=0;
		if (x > 0)a = solve(index + 1, x - 1);
		if (unmatched[index] - x > 0)b = solve(index + 1, x);
		dp[index][x] = (a + b) % MOD;
		return dp[index][x];
	}
}
int main(){
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	cin >> line;
	n = line.length();
	dp.resize(n + 1, vector<int>(n + 1, -1));
	unmatched.resize(n + 1, 0);
	for (i = 1; i < line.length(); i++){
		if (line[i-1] == '(')unmatched[i]=unmatched[i-1]+1;
		else unmatched[i] = unmatched[i - 1] - 1;
	}
	cout << solve(0, 0) << "\n";
	return 0;
}