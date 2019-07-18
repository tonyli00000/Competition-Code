#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <map>
using namespace std;
int i, j, k, m, used[40];
double dist[40][40], path[40][40];

void p(int q, int last) {
	for (i = 0; i < last; i++) {
		if (used[i] == q)return;
	}
	if (q == k)return;
	cout << q + 1 << " ";
	used[last] = q;
	last++;
	p(path[q][k], last);
}
void find(int n) {
	int i, j, k;
	for (i = 0; i < n; i++)dist[i][i] = 1.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			path[i][j] = j;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][k] * dist[k][j] > dist[i][j]) {
					dist[i][j] = dist[i][k] * dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}
int main()
{

	int n, m, tc = 0;
	while (cin >> n && n) {
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				dist[i][j] = 0.0000001;
			}
		}
		for (i = 0; i <= n; i++)dist[i][i] = 1.0;
		int ct = 0;
		map<string, int> name;
		for (i = 0; i < n; i++) {
			string s;
			cin >> s;
			name[s] = ct++;
		}
		cin >> m;
		for (i = 0; i < m; i++) {
			string x, y;
			double z;
			cin >> x >> z >> y;
			dist[name[x]][name[y]] = z;
		}
		find(n);
		cout << "Case " << ++tc << ": ";
		for (i = 0; i < n; i++) {
			if (dist[i][i] > 1.0) {
				cout << "Yes\n";
				break;
			}
		}
		if (i == n)cout << "No\n";
	}
	return 0;

}