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

vector<pair<long, pair<long, long>>> node;

long p[80000];
long getroot(int n) {
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
	long m, n,i,j,k;
	while (cin >> m >> n) {
		if (!m && !n)break;
		string line,x,y;
		map<string, long> name;
		//long ct = 0;
		long z;
		for (i = 0; i < m; i++) {
			cin >> line;
			name[line] = i;
			p[i] = i;
		}
		for (i = 0; i < n; i++) {
			cin >> x >> y >> z;
			node.push_back(make_pair(z, make_pair(name[x], name[y])));
		}
		cin >> line;
		//if (n < m - 1)cout << "Impossible\n";
		//else {
			long long cost = 0;
			sort(node.begin(), node.end());
			for (i = 0; i < n; i++) {
				if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
					cost += node[i].first;
					addnode(node[i].second.first, (node[i].second.second));
				}
			}
			long q = getroot(0);
			for (i = 0; i < n; i++) {
				if (p[i] != getroot(i))break;
			}
			if (i == n)cout << cost << "\n";
			else cout << "Impossible\n";
		}
	//}
    return 0;
}

