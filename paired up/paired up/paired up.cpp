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
int main()
{
	long long n;
	cin >> n;
	map<long long, long long>ct;
	for (i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		ct[y] = x;
	}
	map<long long, long long>::iterator it = ct.end();
	it--;
    return 0;
}

