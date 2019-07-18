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

vector<pair<long, pair<long, long>>> node;

int p[102];

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
	long t, i, j, k;
	
		int n;
		cin >> n;
		node.clear();
		for (i = 0; i <= n; i++) {
			p[i] = i;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				long x;
				cin >> x;
				node.push_back(make_pair(x,make_pair(i, j)));
			}
		}
		sort(node.begin(), node.end());
		long cost = 0;
		for (i = 0; i < node.size(); i++) {
			if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
				cost += node[i].first;
				addnode(node[i].second.first, (node[i].second.second));
			}

		}
		cout << cost << "\n";
	
	return 0;
}
