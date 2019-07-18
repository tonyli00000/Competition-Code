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


using namespace std;

#define MAXN 10010

int a[MAXN][MAXN], connect[MAXN];
bool Free[MAXN];
int n, krochan, min1;

void BFS(int u) {
	int uu, v, tempmin, k;
	vector<int>Queue(n + 5),d(n+5);
	int front, rear;
	front = rear = 1; tempmin = 0;
	Queue[1] = uu = u;
	for (int i = 0; i < n + 5; i++)
		Free[i] = true;
	d[u] = 0; Free[u] = false;
	while (front <= rear) {
		u = Queue[front++];
		for (k = 1; k <= a[u][0]; k++)
			if (Free[a[u][k]]) {
				v = a[u][k];
				d[v] = d[u] + 2;
				if (connect[v]>1) tempmin += d[v];
				Queue[++rear] = v;
				Free[v] = false;
			}
	}
	if (tempmin<min1) {
		min1 = tempmin;
		krochan = uu;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, x, y, i;
		cin >> n >> m;
		for (i = 1; i <= n; i++)
			a[i][0] = connect[i] = 0;
		while (m--) {
			cin >> x; connect[x]++;
			if (!x) continue;
			while (cin >> y && y != 0) {
				a[x][++a[x][0]] = y;
				a[y][++a[y][0]] = x;
				connect[y]++;
				x = y;
			}
		}
		min1 = 99999999;
		krochan = 0;
		for (int i = 1; i <= n; i++)
			if (connect[i]>1) BFS(i);
		cout << "Krochanska is in: " << krochan << "\n";
	}
}