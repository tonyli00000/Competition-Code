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
	int x, y, z,i,j,k;
	while (cin >> x >> y >> z) {
		long long bc[55][55],ct=0;
		for (i = 0; i < 55; i++) {
			for (j = 0; j < 55; j++) {
				bc[i][j] = 0;
			}
		}
		bc[0][0] = 1;
		//for (k = 0; k < y; k++) {
		//	for (i = 1; i <= x; i++) {
		//		for (j = i + a[i]; j <= x; j++) {
		//			bc[j][y - k - 1] += bc[i][y - k - 2];
		//		}
		//	}
		//}
		for (k = 1; k <= x ; k++) {
			for (j = 1; j <= y; j++) {
				for (i = 1; i <= z && k-i>=0; i++) {
					bc[k][j] += bc[k-i][j-1];
				}
			}
		}
		cout << bc[x][y] << "\n";
	}
	return 0;
}
