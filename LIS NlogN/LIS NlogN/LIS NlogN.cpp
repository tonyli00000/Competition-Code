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
vector<int>d;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);
		if (it == d.end()) d.push_back(x);
		else *it = x;
	}
	cout << d.size() << "\n";
	return 0;
}

