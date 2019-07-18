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

vector<int> vertex;
bool connected[40][40];
int mat[40],l;

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int floodfill(int x,int m,int id,int l) {
	int tmax = 0;
	int i;
	for (i = 0; i < m; i++) {
		if (connected[i][x] && mat[i]!=id) {
			mat[x] = id;
			tmax=max(tmax,floodfill(i, m, id,l+1));
			mat[i] = -1;
		}
	}
	return tmax;
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		vertex.clear();
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				connected[i][j] = false;
			}
		}
		for (i = 0; i < m; i++) {
			vertex.push_back(i);
			mat[i] = -1;
		}
		for (i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			connected[a][b] = true;
			connected[b][a] = true;
		}
		int id = 0,max=0;
		for (i = 0; i < m; i++) {
			if (mat[i] == -1) {
				l = 0;
				l=floodfill(i, m, id,0);
				if (l > max)max = l;
				id++;
			}
		}
		cout << max << "\n";
	}
	return 0;
}
