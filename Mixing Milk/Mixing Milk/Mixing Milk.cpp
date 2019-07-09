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
#define v 10000000
using namespace std;

int main()
{
	long long t;
	long long n;
	cin >> t >> n;
	vector<long long>a;
	while (n--){
		long long x;
		long long y;
		cin >> x >> y;
		a.push_back(x*v+y);
	}
	sort(a.begin(), a.end());
	long long ans=0;
	long long ct = 0;
	auto it = a.begin();
	while (t>0){
		long long x = *it / v,y=*it%v;
		if (t >= y){
			ans += x*y;
			t -= y;
		}
		else {
			ans += x*t;
			t = 0;
			break;
		}
		it++;
	}
	cout << ans << "\n";
	return 0;
}
