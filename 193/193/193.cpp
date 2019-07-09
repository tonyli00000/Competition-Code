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

bool connected[102][102];
vector<int> nodes;
bool color[102];
vector<int> colored;

int m;
void solve(int n,int step,int x) {
	colored.push_back(x);
	if (step > m) {
		m = step;
	}
	int i,j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < colored.size(); j++) {
			if (colored[j] == nodes[i] || connected[nodes[i]][colored[j]] || connected[colored[j]][nodes[i]])break;
		}
		if (j == colored.size()) {
			solve(n, step + 1,nodes[i]);
		}
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		colored.clear();
		int a, b;
		cin >> a >> b;
		for (i = 1; i <= a; i++)
			nodes.push_back(i);
		for (i = 1; i <= a; i++) {
			for (j = 1; j <= a; j++) {
				connected[i][j] = false;
			}
		}
		for (i = 0; i < b; i++) {
			int x, y;
			cin >> x >> y;
			connected[x][y] = true;
			connected[y][x]=true;
		}
		m = 0;
		
		solve(a, 0, 12);
		cout << m << "\n";
		for (i = 0; i < colored.size()-1; i++) {
			cout << colored[i] << " ";
		}
		cout << colored[colored.size() - 1] << "\n";
	}
	return 0;
}
