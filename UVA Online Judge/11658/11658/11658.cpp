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
int i, j, k;
int main()
{
	int x, y;
	while (cin >> x >> y){
		if (!x && !y)break;
		vector<int>p(x);
		double t;
		for (i = 0; i < x; i++){
			cin >> t;
			p[i] = t * 100;
		}
		y--;
		if (p[y]>5000){
			cout << "100.00\n";
			continue;
		}
		vector<bool> dp(10000-p[y]+1, false);
		dp[0] = true;
		for (int i = 1; i <= p.size(); i++){
			if (i == y+1)continue;
			for (int j = 10000-p[y]; j >= 0; j--){
				if (dp[j] && j+p[i-1]<=10000-p[y]){
					dp[j + p[i - 1]] = true;
				}
			}
		}
		for (int i = 5000 - p[y]; i <= 10000-p[y]; i++){
			if (dp[i]){
				cout << fixed<<setprecision(2)<<p[y] * 100.0 / (i+p[y]) << "\n";
				break;
			}
		}
	}
	return 0;
}
