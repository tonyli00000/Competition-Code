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

int min(int x, int y) {
	if (x > y)return y;
	else return x;
}
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int x, y, z, i, j, k;
	while (cin >> x >> y >> z) {
		int ways[10005];
		bool beer[10005];
		for (i = 0; i <= z; i++) {
			ways[i] = -1;
		}
		int ct = 1;
		ways[0] = 0;
		for (i =0; i <= z-x; i ++) {
			//ways[i] = ct++;
			if(ways[i]>=0)ways[i + x] = max(ways[i + x], ways[i] + 1);
			//beer[i] = false;
		}
		ct = 1;
		for (i = 0; i <= z - y; i++) {
			//ways[i] = ct++;
			if(ways[i]>=0)ways[i + y] = max(ways[i + y], ways[i] + 1);
			//beer[i] = false;
		}
		if (ways[z] != -1)cout << ways[z] << "\n";
		else {
			for (int i = z; i >= 0; i--)
			{
				if (ways[i] != -1)
				{
					cout << ways[i] << " " << z - i << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
