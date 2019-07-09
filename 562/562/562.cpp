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

int coins[120];
vector<long long>ways;
void solve(int n,int sum) {
	ways[0] = 1;
	int i;
	for (i = 0; i < n; i++) {
		for (int j = coins[i]; j < sum+2; j++) {
			ways[j] += ways[j - coins[i]];
		}
	}
}
int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		ways.clear();
		ways.resize(55000);
		int n,sum=0;
		cin >> n;
		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
			coins[i] = x;
		}
		solve(n, sum);
		for (i = sum / 2;i>=0; i--) {
			if (ways[i] > 0 && ways[sum - i]>0) {
				cout << sum - i - i << "\n";
				break;
			}
		}
	}
	return 0;
}
