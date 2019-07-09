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
	long long p, t, y, x, i, z, max, n;
	map<long long, long long>nt;
	map<long long, long long>a;
	while (cin >> x >> y)
	{
		if (x == 0 && y == 0) return 0;
		if (x>y){
			n = x;
			x = y;
			y = n;
		}
		z = 0;
		nt.clear();
		a.clear();
		for (i = x; i <= y; i++)
		{
			p = i;
			t = 0;
			while (1)
			{
				if (p % 2 == 0) {
					p /= 2;
					t++;
				}
				else {
					p = (3 * p) + 1;
					t++;
				}
				if (p == 1) break;
			}
			if (a[t] != 1) {
				nt[t] = i;
				a[t] = 1;
			}
			if (z == 0){
				max = t;
				z++;
			}
			else if (max<t) max = t;
		}
		cout << "Between " << x << " and " << y << ", " << nt[max] << " generates the longest sequence of " << max << " values." << endl;
	}
	return 0;
