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

vector<vector<long long>>dp(1002, vector<long long>(1002));
int m, n;
vector<int>x(1002);
int main()
{

	while (cin>>n>>m && m && n){
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++){
				dp[i][j] = ((dp[i - 1][j - 1] * x[i]) % m + (dp[i - 1][j]) % m) % m;
			}
		}
		long long ret = 0;
		cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
	}
	return 0;
}