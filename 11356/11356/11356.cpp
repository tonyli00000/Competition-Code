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
	map<string, int>month;
	month["January"] = 1;
	month["February"] = 2;
	month["March"] = 3;
	month["April"] = 4;
	month["May"] = 5;
	month["June"] = 6;
	month["July"] = 7;
	month["August"] = 8;
	month["September"] = 9;
	month["October"] = 10;
	month["November"] = 11;
	month["December"] = 12;
	int i, j, k, tc = 0, t;
	cin >> t;
	while (t--){
		string line;
		cin >> line;
		for (i = 0; i < line.length(); i++){
			if (line[i] == '-')line[i] = ' ';
		}
		stringstream ss(line);
		string a, b, c;
		int y, m, d;
		ss >> a >> b >> c;
		y = (a[3] - '0') + 10 * (a[2] - '0') + 100 * (a[1] - '0') + 1000 * (a[0] - '0');
		m = month[b];
		d = c[1] - '0' + 10 * (c[0] - '0');
		int w,q=0;
		cin >> w;
		while (q <= w){
			d++;
			if (d==31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 )) {
				d = 1;
				m++;
			}
			if (d == 29 && ((y % 400 == 0) && m == 2)){
				d = 1;
				m++;
			}
			if (d == 31 && m == 12){
				d = 1;
				m = 1;
				y++;
			}
			q++;
		}
		
	}
	return 0;
}
