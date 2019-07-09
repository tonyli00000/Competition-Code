#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n,i,j,k;
	string line;
	while (cin >> n && n != 0) {
		cin >> line;
		int p = line.length() / n;
		for (i = 1; i <= n; i++)
		{
			k = i*(p)-1;
			for (j = k; j >= (k - (p) + 1); j--) {
				cout << line[j];
			}
		}
		cout << "\n";
	}
	return 0;
}
