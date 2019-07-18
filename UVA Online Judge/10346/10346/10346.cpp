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
	long long i, n;
	while(cin >> n >> i) {
		cout << n + (n - 1) / (i - 1) << "\n";
	}
	return 0;
}
