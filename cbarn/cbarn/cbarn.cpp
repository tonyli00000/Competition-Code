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

#define INF 10000000000000000
using namespace std;
int n, k;
vector<long long>ct;
vector<vector<long long>>dp;


long long find_dist(int l, int r,long long add){
	long long sum = 0;
	for (int i = l; i < r; i++){
		sum += ct[i] * (i - l+add);
	}
	return sum;
}

long long DP(int l){
	for (int i = 1; i<k; i++){
		for (int j = 1; j <= n; j++) {
			if (dp[j][i]!=-1){
				for (int t = j + 1; t <= n; t++){
					if (dp[t][i + 1] == -1) dp[t][i + 1] = INF;
					dp[t][i + 1] = min(dp[t][i + 1], dp[j][i] + find_dist(j, t,0));
				}
			}
		}
	}
	long long best = INF;
	for (int i = 1; i <= n; i++)
		if (dp[i][k]!=-1)
			best = min(best, dp[i][k] + find_dist(i, n + 1, 0) + find_dist(1, l, n - i + 1));
	return best;
}

int main(){
	//freopen("cbarn.in", "r", stdin);
	//freopen("cbarn.out", "w", stdout);
	int i, j;
	cin >> n >> k;
	ct.resize(n+1);
	for (i = 0; i < n; i++)
		cin >> ct[i+1];
	long long ans = INF;
	for (int a = 1; a <= n; a++){
		dp.assign(n+2,vector<long long>(n + 2, -1));
		dp[a][1] = 0;
		
		ans = min(ans, DP(a));
	}
	cout << ans << "\n";
	return 0;
}

