//PROG: ride
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
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
	string l1, l2;
	cin >> l1 >> l2;
		long long x = 1, y = 1;
		for (int i = 0; i < l1.length(); i++){
			x *= (l1[i] - 'A'+1);
		}
		for (int i = 0; i < l2.length(); i++){
			y *= (l2[i] - '0');
		}
		
		if (x == y)cout << "GO\n";
		else cout << "STAY\n";
	return 0;
}
