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
	int t;
	cin >> t;
	int i, j, k;
	for (i = 0; i < t; i++) {
		cout << "Case " << i + 1 << ": ";
		int a, b;
		cin >> a >> b;
		if (a % 2 == 0)a++;
		if (b % 2 == 0)b--;
		int d = (b-a) / 2 + 1;
		cout << (a + b)*d / 2 << "\n";
	}
	return 0;
}
