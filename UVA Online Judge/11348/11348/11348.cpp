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

using namespace std;

int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		cout << "Case " << k + 1 << ": ";
		int n;
		cin >> n;
		map <int, int> fre;
		multiset <int> arr[55];
		int l[55];
		for (i = 0; i < n; i++) {
			int m;
			cin >> m;
			l[i] = m;
			for (j = 0; j < m; j++) {
				int p;
				cin >> p;
				arr[i].insert(p);
			}
		}
		int sum = 0;
		multiset <int>::iterator it;
		for (i = 0; i < n; i++) {
			multiset <int> used;
			int q = l[i];
			for (it = arr[i].begin(); it!= arr[i].end(); it++) {
				if (used.find(*it) != used.end())q--;
				else {
					for (j = 0; j < n; j++) {
						if (j != i) {
							if (arr[j].find(*it) != arr[j].end())break;
						}
					}
					if (j != n)q--;
					else used.insert(*it);
				}
			}
			l[i] = q;
			sum += q;
		}
		if (n == 0 || sum==0)cout << "\n";
		else {
			for (i = 0; i < n; i++) {

				if (i != n - 1)cout << fixed << setprecision(6) << l[i] * 1.0 / sum*1.0 * 100 * 1.0 << "% ";
				else cout << fixed << setprecision(6) << l[i] * 1.0 / sum*1.0 * 100 * 1.0 << "%\n";


			}
		}
	}
	return 0;
}
