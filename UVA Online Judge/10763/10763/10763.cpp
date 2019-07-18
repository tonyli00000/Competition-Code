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

int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	long n,i,j,k;
	while (cin >> n && n != 0) {
		map<pair<int, int>, int> p;
		for (i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			pair<int, int> l(min(x,y),max(x,y));
			int a = ++p[l];
			if (a == 2)p.erase(l);
		}
		if (p.empty())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
