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
	int Case;
	cin >> Case;
	while (Case--)
	{
		int n;
		cin >> n;
		int sum = 0, i;
		if (!n)cout << "3\n";
		else
		{
			if (n < 0)
				n *= -1;
			for (i = 0; sum < n; i++)
				sum += i;
			i--;
			while ((sum - n) & 1) {
				sum += ++i;
			}
			cout << i << "\n";
		}
		if (Case)cout << "\n";
	}
	return 0;
}