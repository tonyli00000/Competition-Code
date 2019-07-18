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

long ind = 0;
map<int,long> sum;
int q[100000002];

void init() {
	int i;
	long s = 0;
	for (i = 1; i <= 14142; i++) {
		for (int j = s; j < s + i; j++) {
			q[j] = i;
		}
		s += i;
		sum[i] = s;
	}
}
int main()
{
	init();
	long n;
	while (cin >> n && n != 0) {
		map<int,long>::iterator it;
		long p = 0;
		cout << sum[q[n]] - n << " " << q[n] << "\n";
	}
	return 0;
}
