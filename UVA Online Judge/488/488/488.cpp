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
	int i, j;
	int tc,t=1;
	cin >> tc;
	while(tc--){
		if (t++ > 1) cout << "\n";
		int m, n;
		cin >> m >> n;
		while (n > 0) {

			for (i = 1; i <= m; i++) {
				for (j = 1; j <= i; j++) cout << i;
				cout << "\n";
			}
			for (i = m - 1; i >= 1; i--) {
				for (j = 1; j <= i; j++) cout << i;
				cout << "\n";
			}
			n--;
			if (n > 0) cout << "\n";
		}
	}
	return 0;
}

