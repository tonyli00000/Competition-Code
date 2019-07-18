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
	int t;
	cin >> t;
	while (t--) {
		string line;
		cin >> line;
		long long a=0, b=0;
		for (int i = 0; i < 3; i++) {
			long long temp = pow(26, 2-i)*(line[i] - 'A');
			a += temp;
		}
		for (int i = 0; i < 4; i++) {
			b += (pow(10, 3 - i)*(line[i + 4] - '0'));
		}
		if (abs(a - b) <= 100)cout << "nice\n";
		else cout << "not nice\n";
	}
	return 0;
}
