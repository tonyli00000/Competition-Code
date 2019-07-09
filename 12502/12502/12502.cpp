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
	cin >> t;
	while (t--){
		int x, y, z;
		cin >> x >> y >> z;
		double total = x + y,result;
		if (x <= total*1.0 / 3)result = 0;
		else{
			if (x < 2.0*total / 3){
				result = ((double)z * ((double)x - total / 3.0)) / (total / 3.0);
			}
			else result = z;
		}
		cout << fixed << setprecision(0) << result << "\n";
	}
}
