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

		int t;
		cin >> t;

		while (t--) {
			int x;
			int y;
			cin >> x >> y;
			int diff = y - x;
			int count = 0;
			int start = 1;
			bool flag = false;

			while (diff > 0) {
				diff -= start;
				count++;
				if (flag)
					start++;
				flag = !flag;
			}

			cout << count << "\n";
		}

	return 0;
}
