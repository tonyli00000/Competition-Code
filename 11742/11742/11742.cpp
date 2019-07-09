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
	int m, n,con[25][3];
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		int p[8] = { 0,1,2,3,4,5,6,7 };
		int i;
		for (i = 0; i < n; i++) {
			cin >> con[i][0] >> con[i][1] >> con[i][2];
		}
		int ct = 0;
		bool k = true;
		for (i = 0; i < n; i++) {
			int pos1 = -1, pos2 = -1;
			for (int j = 0; j < m; j++) {
				if ((p[j] == con[i][0] || p[j] == con[i][1]) && pos1 == -1)pos1 = j;
				else {
					if ((p[j] == con[i][0] || p[j] == con[i][1]) && pos2 == -1) {
						pos2 = j;
						break;
					}
				}
			}
			if (con[i][2]>0) {
				if (abs(pos1 - pos2) > con[i][2]) {
					k = false;
					break;
				}
			}
			else {
				if (abs(pos1 - pos2) < con[i][2] * -1) {
					k = false;
					break;
				}
			}
		}
		if (k)ct++;
		while (next_permutation(p, p + m)) {
			bool k = true;
			for (i = 0; i < n; i++) {
				int pos1 = -1, pos2 = -1;
				for (int j = 0; j < m; j++) {
					if ((p[j] == con[i][0]||p[j]==con[i][1]) && pos1 == -1)pos1 = j;
					else {
						if ((p[j] == con[i][0] || p[j] == con[i][1]) && pos2 == -1) {
							pos2 = j;
							break;
						}
					}
				}
				if (con[i][2]>0) {
					if (abs(pos1 - pos2) > con[i][2]) {
						k = false;
						break;
					}
				}
				else {
					if (abs(pos1 - pos2) < con[i][2]*-1) {
						k = false;
						break;
					}
				}
			}
			if (k)ct++;
		}
		cout << ct << "\n";
	}
	return 0;
}
