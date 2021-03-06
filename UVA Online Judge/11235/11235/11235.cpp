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

int main()
{
	long m, n,i,j,k;
	vector<long>seg[3];
	while (cin >> m && m!=0) {
		cin >> n;
		seg[0].clear();
		seg[1].clear();
		seg[2].clear();
		seg[0].resize(m, 0);
		seg[1].resize(m, 0);
		seg[2].resize(m, 0);
		bool flag = true;
		long ind = 0;
		int p;
		for (i = 0; i < m; i++) {
			cin >> p;
			if (seg[2][ind] != p) {
				seg[1][ind] = i;
				ind++;
				flag = true;
			}
			if (flag) {
				seg[0][ind] = i+1;
				seg[2][ind] = p;
				flag = false;
			}
		}
		seg[1][ind] = p;
		for (i = 0; i < n; i++) {
			int a, b,max=0;
			cin >> a >> b;
			for (j = 1; j <= ind; j++) {
				if ((seg[0][j] >= a && seg[0][j] <= b)|| (seg[1][j] >= a && seg[1][j] <= b)){
					int x, y;
					if (seg[1][j]>b)y = b;
					else y = seg[1][j];
					if (seg[0][j] < a)x = a;
					else x = seg[0][j];
					if(max<y-x+1)max = y - x+1;
				}
				else {
					if (seg[0][j] <= a && seg[1][j] >= b)max = b - a + 1;
					if(seg[0][j]>b)break;
				}
			}
			cout << max << "\n";
		}
	}
	return 0;
}
