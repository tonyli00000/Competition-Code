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

pair<int,int> maxcard(vector<int>&cards){
	int n = cards.size() - 1;
	vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
	int i, j, k;
	int sum = 0;
	for (i = 1; i <= n; i++){
		dp[i][i] = cards[i];
		sum += cards[i];
	}
	for (k = 2; k <= n; k++){
		for (i = 1; i <= n - k + 1; i++){
			j = i + k - 1;
			dp[i][j] = max(cards[i] - dp[i + 1][j], cards[j] - dp[i][j - 1]);
		}
	}
	int x = ((sum + dp[1][n]) / 2);
	return{ x, sum - x };
}

int main()
{
	int n;
	int i;
	cin >> n;
	vector<int>x(n+1);
	for (i = 0; i < n; i++){
		cin >> x[i+1];
	}
	pair<int, int>q = maxcard(x);
	cout << q.first << " " << q.second << "\n";
	return 0;
}

