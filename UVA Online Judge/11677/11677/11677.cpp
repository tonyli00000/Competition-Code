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
	int a, b, c, d;
	while (cin >> a >> b >> c >> d){
		if (!a && !b && !c && !d)break;
		bool nextday = (a>c || (c == a && d < b));
		int ans = (c - a)*60 + (d - b);
		if (nextday)ans = 1440 + ans;
		cout << ans << "\n";
	}
	return 0;
}
