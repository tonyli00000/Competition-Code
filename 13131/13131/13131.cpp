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
		map<int, int>x, y,rx,ry;
		long n, k;
		cin >> n >> k;
		int i = 2;
		vector<int>div,div2;
		while (n > 1) {
			while (n%i == 0) {
				if (x.find(i) != x.end())div[x[i]]++;
				else {
					div.push_back(1);
					x[i] = div.size() - 1;
				}
			}
		}
		i = 0;
		while (k > 1) {
			while (k%i == 0) {
				if (y.find(i) != y.end())div2[y[i]]++;
				else {
					div2.push_back(1);
					y[i] = div2.size() - 1;
				}
			}
		}
		for (i = 0; i < div2.size(); i++) {
			auto it = y.find(i);
			if (div[x[it->first]]>div2[i])
		}
	}
	return 0;
}

