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
	long long n;
	while (cin>>n && n >= 0) {
		if (n <= 1) cout << 0 << "%\n";
		else cout << 25 * n << "%\n";
	}
	return 0;
}

