#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		long long n,ct;
		cin >> n;
		ct = n;
		map <long long, int> flakes;
		for (i = 0; i < n; i++) {
			long long  o;
			cin >> o;
			if (flakes.find(o) == flakes.end()) {
				flakes[o] = 1;
			}
			else ct--;
		}
		cout << ct << "\n";
	}
	return 0;
}
