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
	long long n;
	while (cin >> n){
		if (n < 8)cout << "Underflow!\n";
		else{
			if (n > 13)cout << "Overflow!\n";
			else {
				long long ans = 1;
				for (int i = 1; i <= n; i++){
					ans *= i;
				}
				cout << ans << "\n";
			}
		}
	}
	return 0;
}
