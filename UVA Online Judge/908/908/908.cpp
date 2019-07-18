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

vector<pair<long long, pair<long, long>>> node;
vector<pair<long long, pair<long, long>>> temp;
long p[1000005];
bool f = false;
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
	long long n,l;
	long long i, j, k,oc=0;
	while (cin >> n) {
		if (f)cout << '\n';
		else f = true;
		oc = 0;
		node.clear();
		for (k = 1; k < n; k++) {
			long x, y, z;
			cin >> x >> y >> z;
			oc += z;
			//temp.push_back(make_pair(z, make_pair(x, y)));
		}
		cin >> n;
		for (i = 0; i < n; i++) {
			long x, y, z;
			cin >> x >> y >> z;
			node.push_back(make_pair(z, make_pair(x, y)));
		}
		cin >> n;
		for (i = 0; i < n; i++) {
			long x, y, z;
			cin >> x >> y >> z;
			node.push_back(make_pair(z, make_pair(x, y)));
		}
		for (i = 0; i <= n + 3; i++) {
			p[i] = i;
		}
		sort(node.begin(), node.end());
		long long cost = 0;
		for (i = 0; i < node.size(); i++) {
			if (getroot(node[i].second.first) != getroot(node[i].second.second)) {
				cost += node[i].first;
				addnode(node[i].second.first, (node[i].second.second));
			}
		}
		cout << oc<<"\n"<<cost << "\n";
	}
	return 0;
}
