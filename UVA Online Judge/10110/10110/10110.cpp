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
	long n,r;
	while (cin >> n && n) {
		r = sqrt(n);
		if (r*r == n)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
