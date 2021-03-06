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

vector<pair<int, pair<int, int>>> node;
int p[1005];

int getroot(int x) {
	if (p[x] != x)return getroot(p[x]);
	else return x;
}
int main()
{
	int i, j, k, t;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, n;
		cin >> m >> n;
		for (i = 0; i <= m; i++) {
			p[i] = i;
		}
		node.resize(n + 1);
		for (i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			node[i] = make_pair(z, make_pair(x, y));
		}
		cout << "Case #" << k+1 << " : ";
		sort(node.begin(), node.begin() + n);
		long cost = 0;
		int ct = 0;
		vector<int> edge;
		for (i = 0; i < n; i++) {
			int x = getroot(node[i].second.first), y = getroot(node[i].second.second);
			if (x != y) {
				cost += node[i].first;
				p[x] = y;
				ct++;
				edge.push_back(i);
			}
		}
		int q = getroot(1);
		for (i = 1; i <= m; i++) {
			if (getroot(i) != q)break;
		}
		if (i != m + 1)cout << "No way\n";
		else {
			long best = 60000000;
			for (j = 0; j < ct; j++) {
				for (i = 0; i <= m; i++) {
					p[i] = i;
				}
				int flag = edge[j];
				long cost = 0;
				for (i = 0; i < n; i++) {
					if (i != flag) {
						int x = getroot(node[i].second.first), y = getroot(node[i].second.second);
						if (x != y) {
							cost += node[i].first;
							p[x] = y;
						}
					}
				}
				int q = getroot(1);
				for (i = 1; i <= m; i++) {
					if (getroot(i) != q)break;
				}
				if (i == m + 1 && cost < best)best = cost;
			}
			if (best == 60000000)cout << "No second way\n";
			else cout << best << "\n";
		}
	}
	return 0;
}
