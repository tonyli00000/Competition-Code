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

int main()
{
	long long i, j, k;
	int t;
	cin >> t;
	while (t--){
		long long n, x;
		cin >> n >> x;
		vector<long long>sum(n + 2,0);
		for (i = 1; i <= n; i++){
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}
		long long ans = n + 2;
		long long Left = 0, Right = 1;
		vector<long long>pos(n + 2);
		pos[0] = 1;
		for (i = 2; i <= n; i++){
			while (Left < Right && sum[i] <= sum[pos[Right - 1]]) Right--;
			pos[Right++] = i;
			while (Left + 1 < Right && sum[i] - sum[pos[Left]] >= x){
				ans = min(ans, i - pos[Left]);
				Left++;
			}
		}
		if (ans >= n + 1)cout << -1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}
