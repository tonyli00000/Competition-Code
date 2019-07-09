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

int cap[70][70];
int f, s, t;
vector<long> dist;
vector<int> p;
void solve(int v, int m) {
	if (v == s) {
		f = m;
		return;
	}
	else {
		if (p[v] != -1) {
			solve(p[v], min(m, cap[p[v]][v]));
			cap[p[v]][v] -= f;
			cap[v][p[v]] += f;
		}
	}
}

int main()
{
	int q,i,j,k;
	cin >> q;
	for (int d = 0; d < q; d++) {
		string name[100][100];
		for (i = 0; i < 70; i++) {
			for (j = 0; j < 70; j++) {
				cap[i][j] = 0;
			}
		}
		int n, ct = 0;
		cin >> n;
		s = 0;
		t = 26 + n + 1;
		for (i = 1; i <= 26; i++) {
			cap[0][i] = 1;
		}
		for (i = 27; i < 27 + n; i++) {
			cap[i][t] = 1;
		}
		for (i = 0; i < n; i++) {
			int x;
			cin >> x;
			for (j = 0; j < x; j++) {
				string y;
				cin >> y;
				if ('A' <= y[0] && y[0] <= 'Z');
				else y[0] -= ('a' - 'A');
				for (int s = 1; s < y.length(); s++) {
					if ('A' <= y[s] && y[s] <= 'Z')y[s] += 'a' - 'A';
				}
				name[i][j] = y;
				cap[y[0] - 'A' + 1][i + 27] = 60000;
			}
			ct += x;
		}
		int tot = 0;
		while (true) {
			f = 0;
			dist.clear();
			dist.resize(70, 60000);
			dist[0] = 0;
			queue<int> q;
			p.clear();
			p.resize(70, -1);
			q.push(s);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)break;
				for (i = 0; i < 54; i++) {
					if (cap[u][i] > 0 && dist[i] == 60000) {
						dist[i] = dist[u] + 1;
						q.push(i);
						p[i] = u;
					}
				}
			}
			solve(t, 60000);
			if (!f)break;
			tot += f;
		}
		cout << "Case #"<<d+1<<":\n";
		vector<string>out;
		//int ct = -1;
		for (i = 27; i <t; i++) {
			for (j = 1; j <= n; j++) {
				if (cap[i][j] == 1) {
					for (int s = 0; s < 30; s++) {
						if (name[i - 27][s][0] == 'A' + j - 1)out.push_back(name[i - 27][s]);
					}
				}
			}
		}
		sort(out.begin(), out.end());
		for (i = 0; i < out.size(); i++) {
			cout << out[i] << "\n";
		}
	}
	return 0;
}
