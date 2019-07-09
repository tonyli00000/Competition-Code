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
#include <cstdio>
#include <cstring>

using namespace std;

bool solve() {
	bool flag = true;
	int n,sum=0;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 1)flag = false;
		sum ^=x;
	}
	if (flag) {
		return (n % 2 == 0);
	}
	else return (sum != 0);
}
int main()
{
	int t;
	cin >> t;
	int i;
	for (i = 0; i < t; i++) {
		if (solve())cout << "John\n";
		else cout << "Brother\n";
	}
	return 0;
}
