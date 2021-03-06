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
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		string line;
		cin >> line;
		long long left[2] = { 0,1 }, mid[2] = { 1,1 }, right[2] = { 1,0 };
		for (i = 0; i < line.length();i++) {
			if (line[i] == 'R') {
				left[0] = mid[0];
				left[1] = mid[1];
				mid[0] = left[0] + right[0];
				mid[1] = left[1] + right[1];
			}
			else {
				right[0] = mid[0];	
				right[1] = mid[1];
				mid[0] = left[0] + right[0];
				mid[1] = left[1] + right[1];
			}
		}
		cout<<mid[0]<<"/"<<mid[1]<<"\n";
	}
	return 0;
}
