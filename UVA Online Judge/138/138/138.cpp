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
	long long n, x = 8, tc = 0;
	double n2;
	while (true)
	{
		n2 = sqrt((x*x + x) / 2);
		n = n2;
		if (n == n2)
		{
			printf("%10lld%10lld\n", n, x);
			tc++;
		}
		if (tc == 10)
			break;
		x++;
	}
	return 0;
}

