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
#include <bitset>
using namespace std;

#define INF 100000000
#define MAX_V 105

int cap[MAX_V][MAX_V], f, s, t;
vector<vector<int>> AdjList;
vector<int> p;

int n, c, cnt = 1;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, cap[p[v]][v]));
		cap[p[v]][v] -= f;
		cap[v][p[v]] += f;
	}
}

int NetworkFlow() {
	int maxx = 0;
	while (true) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)break;
			for (int i = 0; i < AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (cap[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)break;
		maxx += f;
	}
	return maxx;
}

int main()
{
	int n,i,j,k;
	int w = 0;
	while (cin >> n && n) {
		int c;
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				cap[i][j] = 0;
			}
		}
			cin >> s>>t >> c;
			s--;
			t--;
			for (i = 0; i < c; i++) {
				int x, y, z;
				cin >> x >> y >> z;
				cap[x-1][y-1] += z;
				cap[y - 1][x - 1] += z;
			}
			cout << "Network " << ++w << "\n";
			cout << "The bandwidth is ";
			
			cout << NetworkFlow() << ".\n\n";
		
	}
	return 0;
}
