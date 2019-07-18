#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k;
int store[23];

int main()
{
	int t;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m,min=30000,max=0;
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> store[i];
			if (store[i] < min)min = store[i];
			if (store[i] > max)max = store[i];
		}
		cout << 2 * (max - min)<<"\n";
	}
	return 0;
}
