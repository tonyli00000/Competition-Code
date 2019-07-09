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
	int n;
	while (cin>>n && n) {
		int ans=0,i=0;
		//cin >> n;
		//ans = n;
		while (n >= 3) {
			n = n - 3;
			ans++;
			n += 1;
		}
		if(n==2)cout << ans+1 << "\n";
		else cout << ans << "\n";
	}
	return 0;
}
