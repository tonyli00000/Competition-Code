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
	int n;
	while (cin >> n) {
		int tot = n;
		while (n > 1) {
			if (n % 3 == 0) {
				n = n / 3;
				tot += n;
			}
			else {
				if (n % 3 == 1) {
					tot += n / 3;
					n = n / 3 + 1;
				}
				else {
					tot += n / 3 + 1;
					n = (n + 1) / 3 - 1;
				}
			}

		}
		cout << tot << "\n";
	}
	return 0;
}
