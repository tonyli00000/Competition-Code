#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n,i,j,k;
	while (cin >> n && n != 0) {
		vector <bool> range;
		range.resize(200, true);
		range.resize(1700);
		int x[1430],max=0;
		for (i = 0; i < n; i++) {
			cin >> x[i];
			for (j = x[i]; j < x[i] + 200; j++)range[j] = true;
			if (x[i] > max)max = x[i];
		}
		for (i = 0; i <= 1422; i++) {
			if (!range[i])break;
		}
		if (i != 1423)cout << "IMPOSSIBLE\n";
		else {
			int gas;
			for (i = 1422; i < 1700; i++) {
				if (!range[i]) {
					gas = i - 1 - 1422;
					break;
				}
			}
			if (gas < 1422 - max)cout << "IMPOSSIBLE\n";
			else cout << "POSSIBLE\n";
		}
	}
	return 0;
}
