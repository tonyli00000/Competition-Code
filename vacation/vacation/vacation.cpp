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
#include <fstream>
#define INF 1000000000
using namespace std;

int main()
{
	ifstream fin("vacation.in");
	int i, j, k;
	int n, m, hub, q;
	fin >> n >> m >> hub >> q;
	vector<vector<long long>>dist(n + 2, vector<long long>(n + 2, INF));
	for (i = 0; i < m; i++){
		long long x, y, z;
		fin >> x >> y >> z;
		dist[x][y] = z;
		dist[i + 1][i + 1] = 0;
	}
	for (k = 1; k <= n; k++){
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ct = 0;
	long long minn = 0;
	for (i = 0; i < q; i++){
		int x, y;
		fin >> x >> y;
		long long curr = INF;
		for (j = 1; j <= hub; j++){
			if (dist[x][j] != INF && dist[j][y] != INF)curr = min(curr, dist[x][j] + dist[j][y]);
		}
		if (curr != INF){
			ct++;
			minn += curr;
		}
	}
	fin.close();

	ofstream fout("vacation.out");
	fout << ct << "\n";
	fout << minn << "\n";
	return 0;
}
