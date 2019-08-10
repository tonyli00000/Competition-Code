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
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007

#define ALL(a) a.begin(),a.end()
using namespace std;
class Solution {
public:
	int minSwaps(vector<int>& data) {
		int ct = 0;
		int n = data.size();
		for (int i = 0; i < n; i++) {
			if (data[i] == 1)ct++;
		}
		int curr = 0;
		for (int i = 0; i < ct; i++) {
			if (data[i] == 1)curr++;
		}
		int maxx = curr;

		for (int i = 1; i <= n - ct; i++) {
			if (data[i - 1])curr--;
			if (data[i + ct - 1])curr++;
			maxx = max(maxx, curr);
		}
		return ct - maxx;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long

	return 0;
}