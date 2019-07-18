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


#define For(i, a, b) for (int i=a; i<=b; i++)
#define maxN 1005
#define INF 200000000
int n, dist[maxN], V, M;
bool a[maxN][maxN];
double x[maxN], y[maxN], D;

bool valid(int i, int j) {
	double a = x[i] - x[j];
	double b = y[i] - y[j];
	return ((double)(sqrt(a*a + b*b)) <= D);
}

int BFS() {
	queue<int> Q;
	dist[0] = 0;
	Q.push(0);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int v = 0; v < n; v++){
			if (dist[v] == INF && a[u][v]) {
				if (v == 1) return dist[u];
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	char s[30];
	while (cin>>V>>M) {
		if (!V &&!M)break;
		D = V*M*60.0;
		n = 0;
		string line;
		getline(cin, line);
		while (getline(cin,line) && line!="") {
			stringstream ss(line);
			ss >> x[n] >> y[n];
			n++;
		}
		for(int i=0;i<n;i++) {
			a[i][i] = true;
			dist[i] = INF;
			for(int j = i + 1; j < n;j++)
				a[i][j] = a[j][i] = valid(i, j);
		}
		int ans = BFS();
		if (ans == -1)cout << "No.\n";
		else cout << "Yes, visiting " << ans << " other holes.\n";
	}
}