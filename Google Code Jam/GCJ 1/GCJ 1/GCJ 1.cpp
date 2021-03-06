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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		long long n;
		cin >> n;
		vector<long long> odd(n / 2 + n % 2), even(n / 2);
		int x = 0, y = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (i % 2 == 0)odd[x++] = a;
			else even[y++] = a;
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		int ct = 0, curr = 1;
		int a = 0, b = 0;
		bool bad = false;
		vector<long long>r(n);
		while (a < x || b < y) {
			if(a<x)r[ct++] = odd[a++];
			if(b<y)r[ct++] = even[b++];
		}
		for (int i = 0; i < r.size()-1; i++) {
			if (r[i] > r[i + 1]) {
				curr = i;
				bad = true;
				break;
			}
		}
		cout << "Case #" << k << ": ";
		if (!bad)cout << "OK\n";
		else cout << curr << "\n";
	}
	return 0;
}

