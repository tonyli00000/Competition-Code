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
	int n,t=0;
	while (cin >> n) {
		vector<int>b;
		for (int i = 0; i < n;i++) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		map<int, bool>check;
		bool b2 = true;
		for (int i = 0; i < n && b2; i++) {
			for (int j = i + 1; j < n; j++) {
				if (check.find(b[i] + b[j]) != check.end()) {
					b2 = false;
				}
					check[b[i] + b[j]] = true;
			}
		}
		cout << "Case #" << ++t << ": It is ";
		if (b2)cout << "a B2-Sequence.\n";
		else cout << "not a B2-Sequence.\n";
		cout << "\n";
	}
	return 0;
}
