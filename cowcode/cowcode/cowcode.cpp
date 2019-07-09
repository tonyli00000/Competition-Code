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

vector<vector<int>>text;
int main()
{
	string x;
	long long y,i,j,k;
	cin >> x >> y;
	long long temp = x.length();
	long long level = 1;
	while (temp < y) {
		temp *= 2;
		level++;
	}
	long long pos=y;
	while (level > 1) {
		if (pos > temp / 2) {		
			if (pos - temp / 2 - 1 == 0)pos = temp / 2;
			else pos = pos - temp / 2 - 1;
		}
		level--;
		temp /= 2;
	}
	if (pos == 0)pos = x.length();
	cout << x[pos - 1] << "\n";
    return 0;
}

