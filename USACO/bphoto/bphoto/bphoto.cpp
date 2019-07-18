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
long long i, j, k;
long long n;
long long height[100005];
set<long long>l, r;
long long pl = 0, pr, ct = 0;

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> height[i];
		r.insert(height[i]);
	}
	l.insert(height[1]);
	pr = r.size()-1-distance(r.begin(), r.find(height[1]));
	if (pr > 0)ct++;
	for (i = 2; i <= n; i++) {
		l.insert(height[i]);
		pl= l.size() - 1 - distance(l.begin(), l.find(height[i]));
		pr= r.size() - 1 - distance(r.begin(), r.find(height[i]));
		r.erase(r.find(height[i]));
		if (pl > pr && pl > pr * 2)ct++;
		if (pr > pl && pr > pl * 2)ct++;
	}
	cout << ct << "\n";
	return 0;
}

