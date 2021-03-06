#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define INF 10000000
#define MOD 1000000007
using namespace std;
map<int, int>dp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	int maxx = 0,curr;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
		if(maxx<dp[a[i]])maxx = max(maxx, dp[a[i]]),curr=a[i];
	}
	cout << maxx << "\n";
	//int curr = maxx;
	vector<int>out;
	for (int i = n-1; i>=0; i--) {
		if (a[i] == curr) {
			out.push_back(i+1);
			curr--;
			if (maxx == 0)break;
		}
	}
	reverse(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++) {
		cout << out[i];
		if (i != out.size() - 1)cout << " ";
	}
	cout << "\n";
	return 0;
}