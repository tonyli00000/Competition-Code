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

int coins[120],k;
bool flag = false, used[30], r = false;
int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
//		ways.clear();
	//	ways.resize(55000);
		int n, sum = 0,x;
		cin >> x;
		cin >> n;
		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			sum += x;
			coins[i] = x;
		}
		for (i = 0; i < (1 << n); i++) {
			sum = 0;
			for (j = 0; j < n; j++) {
				if (i & 1 << j) {
					sum += coins[j];
				}
			}
			if (sum == x)break;
		}
		//solve(n, 0, x, 0);
		if (i!=1<<n)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
