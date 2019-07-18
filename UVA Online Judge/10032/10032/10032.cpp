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

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		int weight[102],sum=0;
		int n;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> weight[i];
			sum += weight[i];
		}
		//sum /= 2;
		long long ways[45005];
		for (i = 0; i <= sum; i++)ways[i] = 0;
		ways[0] = 1;
		for (i = 0; i < n; i++) {
			for (j = weight[i]; j < 45005; j++) {
				ways[j] += ways[j - weight[i]];
			}
		}
		for (i = sum/2; i >= 0; i--) {
			if (ways[i] != 0 && ways[sum - i] != 0) {
				cout << i << " " << sum - i << "\n";
				break;
			}
		}
	}

	return 0;
}
