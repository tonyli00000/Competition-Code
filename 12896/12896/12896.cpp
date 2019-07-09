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

string a[15];
void gen() {
	a[0] = "0 ";
	a[1] = "0.,?";
	a[1] += '"';
	a[2] = "0abc";
	a[3] = "0def";
	a[4] = "0ghi";
	a[5] = "0jkl";
	a[6] = "0mno";
	a[7] = "0pqrs";
	a[8] = "0tuv";
	a[9] = "0wxyz";
}
int main()
{
	int t, i, j, k;
	gen();
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> j;
		int l[1005];
		
		for (i = 0; i < j; i++) {
			cin >> l[i];
		}
		for (i = 0; i < j; i++) {
			int x;
			cin >> x;
			cout << a[l[i]][x];
		}
		cout << "\n";
	}
	return 0;
}
