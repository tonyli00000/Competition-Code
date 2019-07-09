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
int n, a[1004], sum;

int main()
{
	int t, n;
	int i, j;

	cin >> n;
	for (t=0; t < n; t++) {
		cin >> n;
		for (i = 0; i < n; i++) cin >> a[i];
		sum = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < i; j++)
				if (a[j] <= a[i]) sum++;
		cout << sum << "\n";
	}

	return 0;
}