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
int i, j, k;
vector < pair<int, pair<int, int>>>grid;
vector<vector<int>>neighbor;
bool visited[205];
long long dist(long x1, long y1, long x2, long y2) {
	long x = x2 - x1, y = y2 - y1;
	return (x*x + y*y);
}
void search(int i){
	visited[i] = true;
	for (int j = 0; j < neighbor[i].size(); j++) {
		if (!visited[neighbor[i][j]])search(neighbor[i][j]);
	}
}

int main()
{
	int n;
	cin >> n;
	neighbor.resize(n);
	for (i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		grid.push_back(make_pair(z, make_pair(x, y)));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				if (dist(grid[i].second.first, grid[i].second.second, grid[j].second.first, grid[j].second.second) <= grid[i].first*grid[i].first) {
					neighbor[i].push_back(j);
				}
			}
		}
	}
	int ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n + 3; j++)visited[j] = false;
		search(i);
		int ct = 0;
		for (j = 0; j < n; j++) {
			if (visited[j])ct++;
		}
		ans = max(ct, ans);
	}
	cout << ans << "\n";
    return 0;
}

