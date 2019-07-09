#include <iostream>
#include <cstring>
#include <numeric>
#include <bitset>
using namespace std;

int M, sum, sticks[20];
int dp[1 << 20];

int search(int length, int mask){
	if (dp[mask] != -1)return dp[mask];

	if (length > sum / 4)return 0;
	else if (length == sum / 4){
		if (mask == (1 << M) - 1)return 1;
		length = 0;
	}

	for (int i = 0; i < M; i++){
		if ((mask & 1 << i) == 0 && search(length + sticks[i], mask | 1 << i)){
			return 1;
		}
	}
	dp[mask] = 0;
	return dp[mask];
}

int solve(){
	sum = accumulate(sticks, sticks + M, 0);
	if (sum % 4 != 0)return 0;

	for (int i = 0; i < sizeof(dp); i++){
		dp[i] = -1;
	}
	return search(0, 0);
}

int main()
{
	int N;
	cin >> N;
	while (N--){
		cin >> M;
		for (int i = 0; i < M; ++i)
			cin >> sticks[i];
		int x = solve();
		if (x)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}