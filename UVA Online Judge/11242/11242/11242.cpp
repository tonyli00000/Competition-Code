#include <cstdio>
#include <algorithm>
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

int main() {
	int f, r;
	int fv[10], rv[10];
	double drive[100];

	while (cin>>f && f!=0) {
		cin >> r;
		for (int i = 0; i < f; i++) {
			cin >> fv[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> rv[i];
		}

		int k = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < f; j++) {
				drive[k] = (double)rv[i] / (double)fv[j];
				k++;
			}
		}
		sort(drive, drive + k);

		double maxS = -1;
		for (int i = 0; i < k - 1; i++) {
			maxS = max(maxS, drive[i + 1] / drive[i]);
		}

		cout << fixed << setprecision(2) << maxS << "\n";
	}

	return 0;
}