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
	long long i, j, k,x;
	int p[4] = { 10,15,20,25 }, v[3] = { 300000,400000,300000 };
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> x;
		cout << "Case " << k + 1 << ": ";
		if (x <= 180000)cout << 0 << "\n";
		else {
			x -= 180000;
			double tax=0;
			i = 0;
			while (x > v[i] && i<3) {
				tax += p[i] * 1.0 / 100 * v[i];
				x -= v[i];
				i++;
			}
			if (i == 3)tax += x*0.25;
			else tax += x*p[i] * 1.0 / 100;
			if (tax < 2000)cout << 2000 << "\n";
			else {
				if ((long long)tax == tax)cout << (long long)tax << "\n";
				else cout << (long long)tax + 1 << "\n";
			}
		}
	}
	return 0;
}
