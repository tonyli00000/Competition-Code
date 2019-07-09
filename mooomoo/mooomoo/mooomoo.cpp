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

long long i, j, k;
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, 300);
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if (coins[j] <= i) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount];
}

int main()
{
	int n, b;
	cin >> n >> b;
	vector<int>breed(n),field(n+3,0);
	for (i = 0; i < b; i++){
		cin >> breed[i];
	}
	vector<int>moo(n + 3, 0);
	for (i = 0; i < n; i++){
		cin >> field[i];
	}
	/*for (j = n - 1; j >= 0; j--){
		for (i = 1; i <= j; i++){
			field[j] -= (field[j - i] - i);
		}
	}*/
	int ct = 0;
	int r = 0;
	for (i = 0; i < n; i++){
		r = max(r - 1, 0);
		int v = field[i] - r;
		ct+=coinChange(breed,v);
		r = field[i];
	}
	cout << ct << "\n";
	return 0;
}
