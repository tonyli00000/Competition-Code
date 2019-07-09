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

vector<int>h;
vector<int>v;
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int lis(int c) {
	int maxi = 1;
	for (int i = 0; i < c; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (h[j] < h[i] && v[j] + 1 > v[i]) {
				v[i] = v[j] + 1;
				maxi = max(maxi, v[i]);
			}
		}
	}
	return maxi;
}
int main()
{
	int n,t=0;
	while (cin >> n && n != -1) {
		if (t != 0)cout << "\n";
		h.clear();
		v.clear();
		//h.push_back(60000);
		h.push_back(n);
		v.push_back(1);
		long c = 1;
		while (cin >> n && n != -1) {
			h.insert(h.begin(), n);
			v.push_back(1);
			c++;
		}
		long i, j,max=0;
		cout << "Test #" << ++t << ":\n";
		cout << "  maximum possible interceptions: " << lis(c) << "\n";
	}
	return 0;
}
