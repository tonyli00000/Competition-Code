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
	int t,i,j,k;
	cin >> t;
	for (k = 0; k < t; k++) {
		bool flag = false;
		int n;
		cin >> n;
		vector<vector<bool>> vert;
		vector<vector<bool>> hor;
		vert.resize(n);
		hor.resize(n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				vert[i].push_back(true);
				hor[i].push_back(true);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				int x;
				cin >> x;
				x--;
				if (flag);
				else {
					if (!hor[i][x] || !vert[j][x])flag = true;
					else hor[i][x] = false, vert[j][x]=false;
				}
			}
		}
		if (!flag)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
