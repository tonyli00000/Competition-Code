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

using namespace std;

int ways[30003];
vector<int> coin;
void count(int n,int m)
{
	for (int i = 0; i < 20000; i++)ways[i] = 0;
	ways[0] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = coin[i]; j < 20000; j++) {
			if(ways[j-coin[i]]+1<ways[j])ways[j] = ways[j - coin[i]]+1;
		}
	}
}
int min(int x, int y) {
	if (x > y)return y;
	else return x;
}
int main()
{
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		coin.clear();
		int n;
		cin >> n;
		int m;
		cin >> m;
		for (i = 0; i < m; i++) {
			int x;
			cin >> x;
			coin.push_back(x);
		}
		int dp[30001];

		dp[0] = 0;
		for (int i = 1; i <= 30000; i++)
			dp[i] = 60000;

		for (int i = 0; i < m; i++) {
			for (int v = 30001 - coin[i] - 1; v >= 0; v--)
				if (dp[v] < 60000)
					dp[v + coin[i]] = min(dp[v + coin[i]], dp[v] + 1);
		}
		for (int i = n;; i++) {
			if (dp[i] != 60000) {
				cout << i << " " << dp[i] << "\n";
				break;
			}
		}
		// cout << dp[n] << "\n";
	}
	return 0;
}
