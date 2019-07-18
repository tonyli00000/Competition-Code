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
	int T,i,j,k;
	cin >> T;
	for (i = 0; i < T;i++) {
		int i;
		cin >> i;
		i++;
		vector<int> c;
		while (i--) {
			int cj;
			cin >> cj;
			c.push_back(cj);
		}
		int d, k;
		cin >> d;
		cin >> k;
		long long sum = 0;
		for (int n = 1; n <= k; ++n) {
			sum += n*d;
			if (sum >= k) {
				long long ans = 0;
				for (int j = 0; j<c.size(); j++) {
					ans += ((long long)c[j])*((long long)pow((float)n, (float)j));
				}
				cout << ans << "\n";
				break;
			}
		}
	}
	return 0;
	return 0;
}
