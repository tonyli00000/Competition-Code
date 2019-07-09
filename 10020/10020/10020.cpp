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

using namespace std;

long min(long x, long y) {
	if (x > y)return y;
	else return x;
}
long max(long x, long y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int t;
	long i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		long m;
		cin >> m;
		long x, y,left=-1,right=-1;
		set<pair<long, long>> seg;
		while (cin >> x >> y) {
			if (x == 0 && y == 0)break;
			if (x > m && y > m);
			else {
				if (x < 0 && y < 0);
				else {
					
					if (left == -1 && right == -1) {
						left = min(x,y);
						right = max(x,y);
						seg.insert(make_pair(left, right));
					}
					
				}
			}
		}
	}
	return 0;
}
