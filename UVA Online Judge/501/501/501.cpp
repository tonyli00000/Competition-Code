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
	int m, n,i,j,k;
	while (cin >> m >> n) {
		multiset<long> l;
		multiset<long>::iterator it;
		vector<long>nums;
		vector<long> U;
		for (i = 0; i < m; i++) {
			long x;
			cin >> x;
			nums.push_back(x);
		}
		for (i = 0; i < n; i++) {
			long x;
			cin >> x;
			U.push_back(x);
		}
		l.insert(nums[0]);
		bool flag = true;
		int s = 1;
		int b = 0;
		for (int i = 0, u = 0, a = 0; u < n; ++u, ++i)
		{
			while (a < U[u] && a < n)
				l.insert(nums[a++]);
			auto it = l.cbegin();
			for (int j = 0; j < i; ++j)
				++it;
			cout<<*it<<"\n";
		}
	}
	return 0;
}
