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

int main()
{
	int n;
	while (cin >> n && n){
		vector<int> W(n + 1), L(n + 1);
		for (int i = 1; i <= n;i++)
			cin >> W[i] >> L[i];

		vector<int> dp(6005, 0);
		for (int i =n; i >= 1; i--){
			for (int j = L[i]; j >= 0; j--){
				if (dp[j])dp[j + W[i]] = max(dp[j + W[i]], dp[j] + 1); 
			}
			if (!dp[W[i]])dp[W[i]] = 1;
		}
		cout << *max_element(dp.begin(), dp.end())<<"\n";
	}
	return 0;
}

