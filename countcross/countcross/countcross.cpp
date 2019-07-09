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

long long i, j;
map<pair<pair<int, int>, pair<int, int>>,int>bad;
int dist[10005][10005];
bool solved[105][105];
int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };
long long n, k, r;
void dfs(int x, int y) {
	solved[x][y] = true;
	int i;
	for (i = 0; i < 4; i++) {
		pair<int, int>a = make_pair(x, y),b=make_pair(x+xx[i],y+yy[i]);
		if (x + xx[i]>0 && x + xx[i] <= n && y + yy[i] > 0 && y + yy[i]<=n && bad.find(make_pair(a,b))==bad.end() && !solved[x+xx[i]][y+yy[i]]) {
			dfs(x + xx[i], y + yy[i]);
		}
	}

}
int main()
{
	cin >> n >> k >> r;
	for (i = 0; i < r; i++) {
		vector<int>t(4);
		cin >> t[0] >> t[1] >> t[2] >> t[3];
		pair<int, int>a = make_pair(t[0], t[1]),b=make_pair(t[2],t[3]);
		bad[make_pair(a, b)] = 1;
		bad[make_pair(b, a)] = 1;
	}
	vector<pair<int, int>>location;
	for (i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		location.push_back(make_pair(x, y));
	}	
	int ct = 0;
	for (i = 0; i < k; i++) {
		for (j = 0; j <= n; j++) {
			for (int l = 0; l <= n; l++) {
				solved[j][l] = false;
			}
		}
		dfs(location[i].first, location[i].second);
		for (j = 0; j < k; j++) {
			if (i != j && !solved[location[j].first][location[j].second])ct++;
		}
	}
	cout << ct/2 << "\n";
    return 0;
}

