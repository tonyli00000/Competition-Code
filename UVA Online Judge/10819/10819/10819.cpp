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
vector<int> weight;
vector<int> price;

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n) {
		weight.clear();
		price.clear();
		int x, y;
		for (i = 0; i < n; i++) {
			cin >> x >> y;
			weight.push_back(y);
			price.push_back(x);
		}
		vector<int> s[100];
		for (i = 0; i <= n; i++) {
			s[i].resize(m+400, 0);
		}
		for (i = 0; i <= n; i++) {
			for (j = 0; j < m; j++) {
				s[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (j != 0) {
					if (price[i] <= j) {
						s[i][j] = max(s[i][j], weight[i] + s[i][j - price[i]]);
					}
					else {
						if ((price[i] + (m - j)>2000 && price[i] + (m - j) <= m + 200)) {
							s[i][j] = max(s[i][j], weight[i] + s[i][j+200 - price[i]]);
						}
					}
				}
			}
		}
		cout << s[0][m - 1] << "\n";
	}
	return 0;
}
