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
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		cout << "Test #" << k + 1 << ": ";
		char c;
		cin >> c;
		cin >> c;
		int n;
		cin >> n;
		long long arr[102][102];
		bool p[102][102];
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				p[i][j] = false;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[j][i] == arr[i][j]) {
					p[i][j] = true;
					p[j][i] = true;
				}
			}
		}
		bool flag = false;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (!p[i][j]) {
					flag = true;
					break;
				}
			}
			if (flag)break;
		}
		if (!flag)cout << "Symmetric.\n";
		else cout << "Non-symmetric.\n";
	}

	return 0;
}
