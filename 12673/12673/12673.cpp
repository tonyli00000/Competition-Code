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
	long m, n,i,j,k;
	while (cin >> m >> n) {
		long points = 0;
		vector<int>difference;
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (x <= y) {
				difference.push_back(x - y + 1);
				if (x == y)points += 1;
			}
			else points += 3;
		}
		sort(difference.begin(), difference.end());
		long sum = 0;
		for (i = 0; i < difference.size(); i++) {
			if (difference[i] + sum>n)break;
			else {
				points += 2;
				sum += difference[i];
			}
		}
		cout << points << "\n";
	}
	return 0;
}
