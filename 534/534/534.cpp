#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

vector<pair<double, pair<int, int>>> node;

int p[205];

int getroot(int n) {
	if (p[n] == n)return n;
	else {
		return(getroot(p[n]));
	}
}

void addnode(int i, int j) {
	int x = getroot(i), y = getroot(j);
	p[x] = y;
	p[y] = y;
}
int main()
{
	int t, i, j, k=0;
		int n;
		while (cin >> n && n) {
			node.clear();
			for (i = 0; i <= n; i++) {
				p[i] = i;
			}
			double x[205], y[205];
			for (i = 0; i < n; i++) {
				cin >> x[i] >> y[i];
			}
			long long ct = 0;
			for (i = 0; i < n; i++) {
				for (j = i + 1; j < n; j++) {
					node.push_back(make_pair(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])), make_pair(i, j)));
					ct++;
				}
			}
			sort(node.begin(), node.begin() + ct);
			double cost = 0;
			for (i = 0; i < ct; i++) {
				if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
					cost += node[i].first;
					addnode(node[i].second.first, (node[i].second.second));
				}

			}
			cout << "Scenario #" << ++k << "\n";
			cout << fixed << setprecision(3) << cost << "\n\n";
		}
	return 0;
}
