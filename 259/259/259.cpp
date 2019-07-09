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

int cap[105][105], f, s, t;
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
	int n, i, j, k;
	int w = 0;
	string line;
	for (i = 0; i < 38; i++) {
		for (j = 0; j < 38; j++) {
			cap[i][j] = 0;
		}
	}
	for (i = 27; i <= 36; i++) {
		cap[i][37] = 1;
	}
	vector<int> adj[38];
	//for (i = 1; i <= 26; i++) {
	//	//adj[0].push_back(i);
	//	cap[0][i] = 1;
	//}
	//for (i = 27; i <= 36; i++) {
	//	adj[i].push_back(37);
	//}
	int sum = 0;
	while(true){
		bool flag;
		if (getline(cin, line))flag = false;
		else flag = true;

		if (line == "" || flag) {
			int s = 0, t = 37;
			long tot = 0;
			while (true) {
				f = 0;
				dist.clear();
				dist.resize(45, 60000);
				dist[0] = 0;
				queue<int> q;
				p.clear();
				p.resize(45, -1);
				q.push(s);
				while (!q.empty()) {
					int u = q.front();
					q.pop();
					if (u == t)break;
					for (i = 0; i < 38; i++) {
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
			if (sum != tot)cout << "!\n";
			//else cout << tot << "\n";
			else {
				char out[10];
				for (i = 0; i < 10; i++) {
					out[i] = '_';
				}
				for (i = 27; i <= 36; i++) {
					for (j = 1; j <= 26; j++) {
						if (cap[i][j] == 1)out[i - 27] = j - 1 + 'A';
					}
				}
				for (i = 0; i < 10; i++)
					cout << out[i];

				cout << "\n";
			}
			if (flag)break;
			for (i = 0; i < 45; i++) {
				for (j = 0; j < 45; j++) {
					cap[i][j] = 0;
				}
			}
			//adj[0].clear();
			//for (i = 1; i <= 26; i++) {
			//	adj[0].push_back(i);
			//}
			for (i = 27; i <= 36; i++) {
				cap[i][37] = 1;
			}
			sum = 0;
		}
		else {
			stringstream ss(line);
			string a, b;
			ss >> a >> b;
			cap[0][a[0] - 'A' + 1] = line[1] - '0';
			sum += line[1] - '0';
			//adj[a[0] - 'A' + 1].clear();
			for (i = 0; i < b.length() - 1; i++) {
				cap[a[0] - 'A' + 1][b[i] - '0' + 27] = 60000;
				//adj[a[0] - 'A' + 1].push_back(b[i] - '0'+27);
			}
		}
	}

	return 0;
}
