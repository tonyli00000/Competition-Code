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
	long long m, n;
	while (cin >> m >> n) {
		if(n>m)cout << n - m << "\n";
		else cout << m - n << "\n";
	}
	return 0;
}
