#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int o[3];
void order(int x, int y, int z) {
	int i, j, k;
	o[0] = x;
	o[1] = y;
	o[2] = z;
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 3; j++) {
			if (o[j] < o[i]) {
				int temp = o[j];
				o[j] = o[i];
				o[i] = temp;
			}
		}
	}
	return;
}
int main()
{
	int t,i,j,k;
	while (cin >> t && t > 3) {
		double ans = 0.0;
		for (i = 1; i <= t; i++) {
			for (j = i+1; j <= t; j++) {
				for (k = j+1; k <= t; k++) {
					order(i, j, k);
					if (o[0] + o[1] > o[2]) {
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
