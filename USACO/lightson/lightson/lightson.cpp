/*
ID: tonyli21
PROG: sprime
LANG: C++11
*/
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

int n;
long long m;
bool on[105][105],visited[105][105];
vector<vector<int>>connected;
int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };
queue<pair<int, int>>touched;
int coord(int a, int b){
	return (a - 1)*n + b;
}
pair<int, int> back(int a){
	return(make_pair(a / n + 1, a%n));
}
bool neighbor(int x, int y){
	for (int k = 0; k < 4; k++) {
		if (on[x + xx[k]] [y + yy[k]] && visited[x + xx[k]][ y + yy[k]]) {
			return true;
		}
	}
	return false;
}
void floodfill(int x, int y){
	int i = 0, l = coord(x, y);
	visited[x][y] = true;
	on[x][y] = true;
	//for (int i = 0; i < 4; i++){
	//		touched.push(make_pair(x + xx[i], y + yy[i]));
	//	
	//}
	for (int i = 0; i < connected[l].size(); i++){
		int q = connected[l][i];
		on[(q-1 )/ n + 1][(q-1)%n+1] = true;
		if (neighbor((q - 1) / n + 1,(q - 1) % n + 1) ){
			floodfill((q - 1) / n + 1, (q - 1) % n + 1);
		}
	}
	for (int i = 0; i < 4; i++){
		if (on[x + xx[i]][y + yy[i]] && !visited[x + xx[i]][y + yy[i]]){
			floodfill(x + xx[i], y + yy[i]);
		}
	}
	return;
}
int main()
{
	long long i, j, k;
	//freopen("lightson.in", "r", stdin);
	//freopen("lightson.out", "w", stdout);
	for (i = 0; i <= 100; i++){
		for (j = 0; j <= 100; j++){
			on[i][j] = false;
			visited[i][j] = false;
		}
	}
	cin >> n >> m;
	connected.resize((n+2)*(n + 2));

	for (i = 0; i < m; i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		connected[coord(x, y)].push_back(coord(a, b));
	}

	floodfill(1, 1);

	//while (!touched.empty()){
	//	if (on[touched.front().first][touched.front().second] && !visited[touched.front().first][touched.front().second]){
	//		int a = touched.front().first, b = touched.front().second;
	//		touched.pop();
	//		floodfill(a, b);
	//	}
	//	else touched.pop();
	//}
	int ans = 0;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (on[i][j])ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}

