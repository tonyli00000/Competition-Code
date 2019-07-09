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
	int t, tc = 0,i,j,k;
	cin >> t;
	while (t--){
		int m, n;
		cin >> m >> n;
		int x[105], y[105], r[105];
		for (i = 0; i < m; i++){
			cin >> x[i] >> y[i] >> r[i];
		}
		cout << "Case " << ++tc << ":\n";
		for (i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			bool incoverage = false;
			for (j = 0; j < n; j++){
				if ((x[j] - a)*(x[j] - a) + (y[j] - b)*(y[j] - b) <= r[j]*r[j]){
					incoverage = true;
					break;
				}
			}
			if (incoverage)cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}
