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

vector<int> a[10000];
int main()
{
	int t,i,j,k;
	while (cin >> t) {
		long ct = 0;
		double q = 1.0 / t;
		for (i = t+1;i<=10000; i++) {
			for (j = i; j<10000; j++) {
				double w = 1.0 / i;
				double s = 1.0 / j;
				if (w + s < q)break;
				if (w + s == q) {
					ct++;
					a[ct].push_back(j);
					a[ct].push_back(i);
				}
			}
		}
		cout << ct << "\n";
		for (i = 1; i <=ct; i++) {
			cout << "1/" << t << " = 1/" << a[i][0] << " + 1/" << a[i][1] << "\n";
		}
	}
	return 0;
}
