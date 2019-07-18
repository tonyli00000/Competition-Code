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
	int t,tc=0;
	cin >> t;
	while (t--) {
		int a, b, c, d, e, f, g;
		vector<int>tests;
		tests.resize(3, 0);
		cin >> a >> b >> c >> d >> tests[0] >> tests[1] >> tests[2];
		double grade = 0;
		grade += (a + b);
		grade += c;
		sort(tests.begin(), tests.end());
		grade += (tests[1] + tests[2])*1.0/2;
		grade += d;
		cout << "Case " << ++tc << ": ";
		if (grade >= 90)cout << "A\n";
		else if (grade >= 80)cout << "B\n";
		else if (grade >= 70)cout << "C\n";
		else if (grade >= 60)cout << "D\n";
		else cout << "F\n";
	}
	return 0;
}
