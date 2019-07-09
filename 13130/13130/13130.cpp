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
		vector<int>x;
		for (int i = 0; i < 5; i++) {
			int y;
			cin >> y;
			x.push_back(y);
		}
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			if (x[i] != x[i + 1] - 1) {
				flag = false;
				break;
			}
		}
		if (flag)cout << "Y\n";
		else cout << "N\n";
	}
    return 0;
}

