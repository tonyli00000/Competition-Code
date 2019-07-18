#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;
int main() {
	int n, m, q;
	char s[105];
	int g[150][150];
	int i, j, k;
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		map<string, int> R;
		string rR[150];
		for (i = 0; i < n; i++) {
			cin >> s;
			R[s] = i;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				g[i][j] = 0;
		int n = 0;
		for (map<string, int>::iterator it = R.begin();
			it != R.end(); it++) {
			it->second = ++n;
			rR[n] = it->first;
		}
		cin >> m;
		while (m--) {
			cin >> s >> q;
			int x = R[s];
			while (q--) {
				cin >> s;
				int y = R[s];
				g[x][y] = 1;
			}
		}
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					g[i][j] |= g[i][k] & g[k][j];
		for (i = 1; i <= n; i++) {
			int mark[150] = {};
			for (j = 1; j <= n; j++) {
				if (g[i][j]) {
					for (k = 1; k <= n; k++) {
						if (g[k][j] && g[i][k]) {
							mark[j] = 1;
							break;
						}
					}
				}
			}
			int p = 0;
			for (j = 1; j <= n; j++)
				if (g[i][j] && mark[j] == 0)
					p++;
			if (p > 0) {
				printf("%s %d", rR[i].c_str(), p);
				for (j = 1; j <= n; j++)
					if (g[i][j] && mark[j] == 0)
						printf(" %s", rR[j].c_str());
				puts("");
			}
		}

	}
	return 0;
}