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
	int n,t;
	cin >> t;
	while (t--) {
		int ans = 0, i = 0;
		//cin >> n;
		//ans = n;
		int a, b, c;
		cin >> a >> b >> c;
		n = a + b;
		while (n >= c) {
			n = n - c;
			ans++;
			n += 1;
		}
		
		cout << ans << "\n";
	}
	return 0;
}
