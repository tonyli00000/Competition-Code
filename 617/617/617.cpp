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
	double n,a,b,c,d;
	int t, i, j, k,ct=0;
	while (cin >> t && t != -1) {
		bool p[67];
		for (i = 0; i < t; i++) {
			cin >> a >> b >> c >> d;
			for (j = 30; j <= 60; j++) {
				if (1.0*a / j * 3600.0 / 1.0/((b + c + d)*1.0) - int(a*3600 / j / (b + c + d)) <= b / (b + c + d));
				else p[j] = false;
			}
		}
		bool flag = false, l = false;
		bool pre = false;
		int start[67], end[67],ind=0;
		for (i = 30; i <= 60; i++) {
			if (p[i] && !pre) {
				start[ind] = i;
				end[ind] = i;
			}
			if (!p[i] && pre) {
				end[ind] = i - 1;
				ind++;
			}
			pre = p[i];
		}
		cout << "Case " << ++ct << ": ";
		if (ind == 0) {
			cout << "No acceptable speeds.\n";
		}
		for (i = 0; i < ind-1; i++) {
			if (start[i] == end[i])cout << start[i] << ", ";
			else cout << start[i] << "-" << end[i] << ", ";
		}
		if (start[ind-1] == end[ind-1])cout << start[ind-1] << ", ";
		else cout << start[ind-1] << "-" << end[ind-1] << ", ";
		cout << "\n";
	}
	return 0;
}
