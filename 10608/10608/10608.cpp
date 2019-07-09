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

int p[30005], rk[30005];
vector<int>nodes;
int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
void unionset(int q, int w) {
	if (rk[q] > rk[w]) {
		for (int i = 0; i < nodes.size(); i++) {
			if (p[nodes[i]] == w) {
				p[nodes[i]] = p[q];
				rk[nodes[i]] -= (rk[q] - rk[w]);
			}
		}
		//p[w] = p[q];
	}
	else {
		if (rk[q] == rk[w])rk[w]++;
		for (int i = 0; i < nodes.size(); i++) {
			if (p[nodes[i]] == q) {
				p[nodes[i]] = p[w];
				rk[nodes[i]] -= (rk[w] - rk[q]);
			}
		}
		//p[q] = p[w];
	}
}

int main()
{
	long long t, i, j, k;
	cin >> t;
	for (k = 0; k<t; k++) {
		long long m, n;
		cin >> m >> n;
		nodes.clear();
		for (i = 0; i<=m; i++) {
				p[i] = i;
				rk[i] = 0;
			}
		for (i = 0; i<n; i++) {
			int a, b;
			cin >> a >> b;
			for (j = 0; j<nodes.size(); j++) {
				if (nodes[j] == a)break;
			}
			if (j == nodes.size())nodes.push_back(a);
			for (j = 0; j<nodes.size(); j++) {
				if (nodes[j] == b)break;
			}
			if (j == nodes.size())nodes.push_back(b);
			int r = findset(a), t = findset(b);
			if (r != t)unionset(r, t);
		}
		map<int, int>max;
		int f = nodes.size();
		for (i = 0; i<f; i++) {
			max[p[nodes[i]]]++;
			//cout<<rk[nodes[i]]<<" ";
		}
		//cout<<"\n";
		map<int, int>::iterator it;
		int l = 0;
		for (it = max.begin(); it != max.end(); it++) {
			if (it->second>l)l = it->second;
		}
		cout << l << "\n";
	}
	return 0;
}
