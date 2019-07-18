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
#include <climits>

using namespace std;
int i, j, k;
long maxProduct(vector<long>& nums,int n) {
	long frontProduct = 1, backProduct = 1;
	long ans = -100000;
	for (int i = 0; i < n; i++) {
		frontProduct *= nums[i];
		backProduct *= nums[n - i - 1];
		ans = max(ans, max(frontProduct, backProduct));
		if (frontProduct == 0)frontProduct = 1;
		if (backProduct == 0)backProduct = 1;
	}
	return ans;
}
int main()
{
	long x;
	while (cin >> x){
		vector<long>y(100);
		y[0] = x;
		int ct = 1;
		for (i = 1; cin >> x && x != -999999; i++){
			y[i] = x;
			ct++;
		}
		cout << maxProduct(y, ct)<<"\n";
	}
	return 0;
}

