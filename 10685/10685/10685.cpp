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
vector<string>nodes;
int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
void unionset(int q, int w) {
	if (rk[q] > rk[w]) {
		for (int i = 0; i < nodes.size(); i++) {
			if (p[i] == w) {
				p[i] = p[q];
				rk[i] -= (rk[q] - rk[w]);
			}
		}
		//p[w] = p[q];
	}
	else {
		if (rk[q] == rk[w])rk[w]++;
		for (int i = 0; i < nodes.size(); i++) {
			if (p[i] == q) {
				p[i] = p[w];
				rk[i] -= (rk[w] - rk[q]);
			}
		}
		//p[q] = p[w];
	}
}

int main()
{
	long long t, i, j, k;
		long long m, n;
		while (cin >> m >> n) {
			if (m == 0 && n == 0)break;
			nodes.clear();
			string temp;
			for (i = 0; i < m; i++)
				cin >> temp;
			for (i = 0; i <= m; i++) {
				p[i] = i;
				rk[i] = 0;
			}
			for (i = 0; i < n; i++) {
				string a, b;
				int o, l;
				cin >> a >> b;
				for (j = 0; j < nodes.size(); j++) {
					if (nodes[j] == a) {
						o = j;
						break;
					}
				}
				if (j == nodes.size()) {
					nodes.push_back(a);
					o = j;
				}
				for (j = 0; j < nodes.size(); j++) {
					if (nodes[j] == b) {
						l = j;
						break;
					}
				}
				if (j == nodes.size()) {
					nodes.push_back(b);
					l =j;
				}
				int r = findset(o), t = findset(l);
				if (r != t)unionset(r, t);
			}
			map<int, int>max;
			int f = nodes.size();
			for (i = 0; i < f; i++) {
				max[p[i]]++;
				//cout<<rk[nodes[i]]<<" ";
			}
			//cout<<"\n";
			map<int, int>::iterator it;
			int l = 0;
			for (it = max.begin(); it != max.end(); it++) {
				if (it->second > l)l = it->second;
			}
			if (l == 0)cout << 1 << "\n";
			else cout << l << "\n";
		}
	return 0;
}
