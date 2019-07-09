/*
ID:tonyli21
PROG:range
LANG:C++11
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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int i, j, k;
using namespace std;
int main(){
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(n + 1));//dp[i][j]=maximum side length of a square with upper left corner (i,j)
	vector<int>ret(251,0);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			char c;
			cin >> c;
			dp[i][j] = c - '0';
		}
	}
	for (i = n - 2; i >= 0; i--){
		for (j = n - 2; j >= 0; j--){
			if (dp[i][j])dp[i][j] = min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1])) + 1;
			if (dp[i][j] > 1){
				for (int k = 2; k <= dp[i][j]; k++){
					ret[k]++;
				}
			}
		}
	}
	for (i = 2; i <= n; i++){
		if (!ret[i])break;
		cout << i << " " << ret[i] << "\n";
	}
	return 0;
}