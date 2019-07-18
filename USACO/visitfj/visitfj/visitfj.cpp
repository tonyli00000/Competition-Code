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

long long n, i, j, k, t;
long long grass[105][105];
long long dist[105][105][3];
int xx[4] = { 1, 0, 0, -1 };
int yy[4] = { 0, 1, -1, 0 };
bool visited[105][105][3];

void floodfill(int x, int y, int z,int x1,int y1){
	if (x == 0 && y == 0)visited[0][0][0]=true;
	else {
		visited[x][y][z] = true;
		if (x1 == 0 && y1 == 0)dist[x][y][0] = min(dist[x][y][0], dist[x1][y1][0] + t);
	
		else{
			if (z == 2)dist[x][y][z] = min(dist[x][y][z], dist[x1][y1][(z + 2) % 3] + t + grass[x][y]);
			else dist[x][y][z] = min(dist[x][y][z], dist[x1][y1][(z + 2) % 3] + t);
		}
	}
	int i;
 	for (i = 0; i < 4; i++){
		if (x + xx[i] >= 0 && x + xx[i] < n && y + yy[i] >= 0 && y + yy[i] < n && make_pair(x + xx[i], y + yy[i]) != make_pair(0, 0)){
			if (!visited[x + xx[i]][y + yy[i]][(z + 1) % 3])floodfill(x + xx[i], y + yy[i], (z + 1) % 3,x,y);
		}
	}

}
int main()
{
	cin >> n >> t;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cin >> grass[i][j];
			visited[i][j][0] = false;
			visited[i][j][1] = false;
			visited[i][j][2] = false;
			dist[i][j][0] = 9999999999999;
			dist[i][j][1] = 9999999999999;
			dist[i][j][2] = 9999999999999;
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0][0] = 0;
	floodfill(0, 0, -1,0,0);

	long long ans = 100000000000;
	for (i = 0; i < 3; i++){
		ans = min(dist[n - 1][n - 1][i], ans);
	}
	cout << ans << "\n";


	return 0;
}
