#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 110
int n, p, k[MAXN];
int casenumber;

int main()
{
	int i, j, c;
	int t;
	cin >> t;
	for (int q = 0; q < t;q++){
		int x, y;
		cin >> x >> y;
		for (i = 0; i < y; i++) cin >> k[i];

		c = 0;
		for (i = 1; i <= x; i++)
			if ((i % 7 > 0) && (i % 7 < 6)) {
				for (j = 0; j < y; j++)
					if (i % k[j] == 0) {
						c++; break;
					}
			}

		cout << c << "\n";
	}
	return 0;
}
