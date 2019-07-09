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
	int t;
	int d, i;
	cin >> t;
	while (t--){
		cin >> d >> i;
		i--;
		int ans = 0;
		for (int j = 1; j<d; j++){
			ans <<= 1;
			ans |= (i & 1);
			i >>= 1;
		}
		ans += (1 << (d - 1));
		cout << ans << "\n";
	}
	return 0;
}

