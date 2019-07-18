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

void LIS(vector<int>arr){
	int n = arr.size();
	vector<int>dp(n),solution(n);
	dp.assign(n, 1);
	for (int i = 0; i < n; i++){
		solution[i] = i;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					solution[i] = j;
				}
			}
		}
	}
	int ind = 0;
	for (int i = 1; i < n; i++){
		if (dp[i]>dp[ind])ind = i;
	}
	cout<<"Max hits: "<<dp[ind]<<"\n";
	vector<int>out;
	int i;
	for (i = ind; solution[i] != i; i = solution[i]){
		out.push_back(arr[i]);
	}
	out.push_back(arr[i]);
	reverse(out.begin(), out.end());
	for (auto i : out){
		cout << i << "\n";
	}
}
int main()
{
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	getline(cin, line);
	while (t--){
		vector<int>arr;
		while (getline(cin, line) && line != ""){
			stringstream ss(line);
			int x;
			ss >> x;
			arr.push_back(x);
		}
		LIS(arr);
		if (t)cout << "\n";
	}
	return 0;
}

