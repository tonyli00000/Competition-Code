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
	long long a, l,temp,tc=0;
	while (cin >> a >> l){
		if (a < 0 && l < 0)break;
		long long ct = 1;
		temp = a;
		while (true){
			if (a == 1)break;
			if (a % 2 == 0){
				a = a / 2;
				ct++;
			}
			else{
				a = 3 * a + 1;
				if (a > l)break;
				ct++;
			}
		}
		cout << "Case "<<++tc<<": A = "<<temp << ", limit = " << l << ", number of terms = " << ct << "\n";
	}
	return 0;
}
