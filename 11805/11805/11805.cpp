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
	int t, tc = 0;
	cin >> t;
	while (t--) {
		int n, k, p;
		cin >> n >> k >> p;
		for (int i = 0; i < p; i++) {
			if (k == n)k = 1;
			else k++;
		}
		cout << "Case " << ++tc << ": " << k << "\n";
	}
	return 0;
}
