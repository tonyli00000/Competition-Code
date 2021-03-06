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
#define INF 10000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;
	cin >> t;
	set<string>cow;
	string x, y;
	while (t--) {
		string s;
		cin >> s;
		if (s == "BUY") {
			cin >> x;
			cow.insert(x);
		}
		else {
			cin >> x >> y;
			cow.insert(x);
			set<string>d;
			for (auto jt = cow.find(x); jt != cow.end(); jt++) {
				if (x.compare(*jt)<=0 && y.compare(*jt)>=0)d.insert(*jt);
				if (y.compare(*jt)<0)break;
			}
			for (auto jt : d) {
				cow.erase(jt);
			}
		}
	}
	for (auto it : cow) {
		cout << it << "\n";
	}
	return 0;
}