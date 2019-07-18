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
	int n;
	while (cin >> n && n) {
		long long sum=0;
		for (int i = 1; i <= n; i++) {
			sum += i*i;
		}
		cout << sum << "\n";
	}
	return 0;
}