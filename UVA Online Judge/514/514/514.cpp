#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int i, j, k;
	int t;

	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;
		while (true) {
			int x[1000];
			cin >> x[0];
			if (x[0] == 0) {
				cout << "\n";
				break;
			}
			for (i = 1; i < n; i++) {
				cin >> x[i];
			}

			int pos = 1, ind = 0;
			stack<int> train;
			while (pos <= n) {
				train.push(pos);

				while (train.size()>0 && train.top() == x[ind] && ind<n) {
					train.pop();
					ind++;
				}

				pos++;
			}

			if (train.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}
