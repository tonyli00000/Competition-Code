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

long ways[303][303];
long solve(int x, int l, int l2) {
	int i, j, k;
	for (i = 0; i <= x; i++) {
		for (j = 0; j <= x; j++) {
			ways[i][j] = 0;
		}
	}
	//for (i = 0; i <= x; i++)ways[i][i] = 1;
	ways[0][0] = 1;
	for (i = 1; i <= x; i++) {
		for (j = 1; j <= x; j++) {
			for (k = i; k >0; k--) {
				ways[i][j] += ways[i - k][j - 1];
				if (k < i / 2+i%2 && ways[i - k][j - 1]>0 && i!=j)ways[i][j]--;
				
			}
		}
	}
	long sum = 0;
	for (i = l; i <= l2; i++) {
		sum += ways[x][i];
	}
	return sum;
}
int main()
{
	string line;
	int i, j, k;
	while (getline(cin, line)) {
		string l;
		stringstream ss(line);
		int ct = 0, a[3] = { 0,0,0 };
		while (ss >> l) {
			int m = 1;
			for (i = l.length() - 1; i >= 0; i--) {
				a[ct] += (l[i] - '0')*m;
				m *= 10;
			}
			ct++;
		}
		if (ct == 1) {
			cout << solve(a[0], 1, a[0]) << "\n";
		}
		else {
			if (ct == 2)cout << solve(a[0], 1, a[1]) << "\n";
			else cout << solve(a[0], a[1], a[2]) << "\n";
		}
	}
	return 0;
}
