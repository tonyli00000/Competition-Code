#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<set<int>>p(n + 1);	set<int>ret;
	for (int i = 1; i <= n; i++) {
		p[i].insert(0);
	}

	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		for (int j = x; j <= y; j++) {
			vector<int>a;
			for(auto it:p[j]){
				if (it + z > n)break;
				a.push_back(it + z);
				ret.insert(it + z);
			}
			for (int i = 0; i < a.size(); i++) {
				p[j].insert(a[i]);
			}
		}
	}
	cout << ret.size() << "\n";
	bool first = true;
	for (auto it : ret) {
		if (first) {
			cout << it;
			first = false;
		}
		else {
			cout << " " << it;
		}
	}
	cout << "\n";
	return 0;
}