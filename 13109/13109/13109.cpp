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
	long long t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		long long m, n,ct=0;
		cin >> m >> n;
		vector<int>elephants;
		for (i = 0; i < m; i++) {
			int x;
			cin >> x;
			elephants.push_back(x);
		}
		sort(elephants.begin(), elephants.end());
		for (i = 0; i < elephants.size(); i++) {
			n -= elephants[i];
			if (n < 0)break;
			ct++;
		}
		cout << ct << "\n";
	}
	return 0;
}
