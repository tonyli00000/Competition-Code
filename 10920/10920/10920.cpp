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
	long long x, y,i,j,k;
	while (cin >> x >> y){
		if (!x && !y)break;
		//vector<vector<int>>mat(x, vector<int>(x));
		int len = 1,tot=1,dir=0,dx=0,dy=0,xi=x/2+1,yi=x/2+1;
		//mat[x / 2][x / 2] = 1;
		while (tot < y){
			for (i = 0; i < 2; i++){
				int a = len;
				if (tot + len>y)a = y - tot;
				tot += a;
				if (dir == 0){
					dy += a;
					dir = 1;
					continue;
				}
				if (dir == 1){
					dx -= a;
					dir = 2;
					continue;
				}
				if (dir == 2){
					dy -= a;
					dir = 3;
					continue;
				}
				dx += a;
				dir = 0;
			}
			len++;
		}
		cout << "Line = " << dy + yi << ", column = " << dx + xi << ".\n";
	}
	return 0;
}
