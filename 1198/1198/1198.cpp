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
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<long>>path(n + 1, vector<long>(n + 1));
	vector<vector<long>>shortest(n + 1, vector<long>(n + 1,100));
	for (int i = 0; i < shortest.size(); i++)
		shortest[i][i] = 0;
	for (int i = 1; i <= n; i++)
		path[i][i] = 1L << i;
	for (int i = 1; i <= n; i++) {
		string inp;
		getline(cin, inp);
		getline(cin, inp);
		stringstream ss(inp);
		int k;
		while(ss>>k) {
			shortest[i][k] = 1;
			path[i][k] = path[i][i] | path[k][k];
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (shortest[i][j] == shortest[i][k] + shortest[k][j]) {
					path[i][j] |= path[i][k] | path[j][k];
				}
				else if (shortest[i][j] > shortest[i][k] + shortest[k][j]) {
					shortest[i][j] = shortest[i][k] + shortest[k][j];
					path[i][j] = path[i][k] | path[j][k];
				}
			}
	int tc;
	cin >> tc;
	while (tc--) {
		string inp;
		getline(cin, inp);
		getline(cin, inp);
		stringstream ss(inp);
		vector<int>ind;
		int x;
		while (ss >> x)ind.push_back(x);
		long res = 0;
		for (int i = 0; i < ind.size(); i++)
			for (int j = i; j < ind.size(); j++) {
				res |= path[ind[i]][ind[j]];
			}
		if (res == ((1L << n) - 1) << 1)
			cout << "yes\n";
		else
			cout << "no\n";

	}
	return 0;
}