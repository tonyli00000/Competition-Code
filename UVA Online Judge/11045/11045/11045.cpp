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

typedef vector<int> vi;

#define MAX_V 200
#define INF 1000000000

int cap[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;

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

int main() {
	int m, n, q,i,j,k;
	cin >> q;

	for (k = 0; k < q;k++) {
		cin >> n >> m;
		
		for (i = 0; i < 200; i++) {
			for (j = 0; j < 200; j++) {
				cap[i][j] = 0;
			}
		}
		for (i = 1; i <= 6; i++) {
			cap[0][i] = n / 6;
		}

		for (i = 7; i < 7 + m; i++) {
			cap[i][7 + m] = 1;
		}

		for (i = 7; i < 7 + m; i++) {
			string s;
			cin >> s;
			if (s=="XXL")cap[1][i] = 1;
			else if (s == "XL")cap[2][i] = 1;
			else if (s == "L")cap[3][i] = 1;
			else if (s == "M")cap[4][i] = 1;
			else if (s == "S")cap[5][i] = 1;
			else if (s == "XS")cap[6][i] = 1;
			cin >> s;
			if (s == "XXL")cap[1][i] = 1;
			else if (s == "XL")cap[2][i] = 1;
			else if (s == "L")cap[3][i] = 1;
			else if (s == "M")cap[4][i] = 1;
			else if (s == "S")cap[5][i] = 1;
			else if (s == "XS")cap[6][i] = 1;
		}
		s = 0;
		t = 7 + m;
		mf = 0;
		while (1) {
			f = 0;
			vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < MAX_V; v++)
					if (cap[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
			}
			augment(t, INF);
			if (!f)break;
			mf += f;
		}

		if (m == mf)cout<<"YES\n";
		else cout << "NO\n";
	}

	return 0;
}