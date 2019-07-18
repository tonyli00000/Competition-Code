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

using namespace std;

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		int n,sum=0,ans=0;
		vector<int> num;
		cin >> n;
		for (i = 0; i < n-1; i++) {
			int x;
			cin >> x;
			num.push_back(x);
		}
		int start = 1,a=0,b=0,c=0;
		for (i = 0; i < n-1; i++) {
			sum += num[i];
			if (sum > ans || (sum == ans && i - a > b - c)) {
				ans = sum;
				b = i;
				c = a;
			}
			if (sum < 0) {
				sum = 0;
				a = i;
			}
		}
		if (ans > 0)cout << "The nicest part of route " << k + 1 << " is between stops " << c + 2 << " and " << b + 2 << "\n";
		else cout << "Route " << k + 1 << " has no nice parts\n";
	}
	return 0;
}
