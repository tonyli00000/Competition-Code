
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
int n;
int p[65];
int t;

int main()
{
	int i, j, ct;

	cin >> t;

	while (t > 0) {
		t--;
		cin >> n;
		for (i = 0; i < n; i++) cin >> p[i];

		ct = 0;
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++)
				if (p[i] > p[j]) ct++;
		}

		cout << "Optimal train swapping takes " << ct << " swaps.\n";
	}

	return 0;
}