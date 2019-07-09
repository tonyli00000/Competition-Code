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


int LIS(vector<int>arr,vector<int>width){
	int n = arr.size();
	vector<int>dp(n);
	for (int i = 0; i < n; i++){
		dp[i] = width[i];
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (dp[j] + width[i] > dp[i]){
					dp[i] = dp[j] + width[i];
				}
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int LDS(vector<int>arr, vector<int>width){
	int n = arr.size();
	vector<int>dp(n);
	for (int i = 0; i < n; i++){
		dp[i] = width[i];
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i] < arr[j]){
				if (dp[j] + width[i] > dp[i]){
					dp[i] = dp[j] + width[i];
				}
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}
int main()
{
	int t,i,j,k;
	cin >> t;
	for (k = 1; k <= t; k++){
		int n;
		cin >> n;
		vector<int>x(n), y(n);
		for (i = 0; i < n; i++){
			cin >> x[i];
		}
		for (i = 0; i < n; i++){
			cin >> y[i];
		}
		int a = LIS(x, y), b = LDS(x, y);
		cout << "Case " << k << ". ";
		if (a >= b)cout << "Increasing (" << a << "). Decreasing (" << b << ").\n";
		else cout << "Decreasing (" << b << "). Increasing (" << a << ").\n";
	}
	return 0;
}

