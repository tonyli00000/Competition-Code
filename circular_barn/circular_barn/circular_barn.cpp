/*
ID: tonyli21
PROG: cbarn
LANG: C++
*/
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
	//freopen("cbarn.in", "r", stdin);
	//freopen("cbarn.out", "w", stdout);
	int n;
	vector<int>c;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;
		c.push_back(x);
	}
	long long ans = 100000000;
	for (int i = 0; i<n; i++) {
		vector<int>r(n);
		for (int j = 0; j < n; j++)
			r[j] = c[(i + j) % n];
		int sum = 0;
		bool flag = true;
		for (int j = n - 1; j >= 0; j--) {
			sum+= r[j];
			if (sum > n - j) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		long long energy = 0;
		int zero = n - 1;
		while (zero >= 0 && r[zero] != 0) zero--;
		for (int j = zero - 1; j >= 0; j--) {
			while (r[j] > 0) {
				if (zero == -1 || zero < j) break;
				r[j]--;
				r[zero]++;
				energy += (zero - j)*(zero - j);
				while (zero >= 0 && r[zero] != 0) zero--;
			}
		}
		ans = min(ans, energy);
	}
	cout << ans << "\n";
	return 0;
}




